// 캔버스 세팅
let canvas;
let ctx;
canvas = document.createElement("canvas");
ctx = canvas.getContext("2d");
canvas.width = 400;
canvas.height = 700;
document.body.appendChild(canvas);

let backgroundImage, spaceshipImage, bulletImage, enemyImage, gameOverImage;
let gameOver = false; // true면 게임이 끝남, false면 게임이 안끝남.
let score = 0;

// 우주선 좌표
let spaceshipX = canvas.width / 2 - 32;
let spaceshipY = canvas.height - 64;

let bulletList = []; // 총알들을 저장하는 리스트

function Bullet() {
  this.x = 0;
  this.y = 0;
  this.init = () => {
    this.x = spaceshipX - 3;
    this.y = spaceshipY - 64;
    this.alive = true; //true면 살아있는 총알, false면 죽은 총알

    bulletList.push(this);
  };
  this.update = function () {
    this.y -= 7;
  };

  this.checkHit = () => {
    /* 총알.y <= 적군.y and 
총알.x >= 적군.x and 총알.x <= 적군.x+너비*/
    for (let i = 0; i < enemyList.length; i++) {
      if (
        this.y <= enemyList[i].y &&
        this.x >= enemyList[i].x &&
        this.x <= enemyList[i].x + 48
      ) {
        //총알이 죽게됨, 적군이 없어짐, 점수획득
        score++;
        this.alive = false; //죽은 총알
        enemyList.splice(i, 1); // i번째에 있는거 하나를 잘라냄.
      }
    }
  };
}

function generateRandomValue(min, max) {
  let randomNum = Math.floor(Math.random() * (max - min + 1)) + min; // 최대값 최소값 사이에서 랜덤값 받는법
  return randomNum;
}

let enemyList = [];
function Enemy() {
  this.x = 0;
  this.y = 0;
  this.init = () => {
    this.y = 0;
    this.x = generateRandomValue(0, canvas.width - 48); // 최대, 최소 받음

    enemyList.push(this);
  };
  this.update = function () {
    this.y += 1.5; // 적군의 속도 조절

    if (this.y >= canvas.height - 48) {
      gameOver = true;
      console.log("gameover");
    }
  };
}

function loadImage() {
  backgroundImage = new Image();
  backgroundImage.src = "images/backgroundImage.png";

  spaceshipImage = new Image();
  spaceshipImage.src = "images/spaceship.png";

  bulletImage = new Image();
  bulletImage.src = "images/bullet.png";

  enemyImage = new Image();
  enemyImage.src = "images/enemy.png";

  gameOverImage = new Image();
  gameOverImage.src = "images/gameover.png";
}

let keysDown = {};
function setupKeyboardListener() {
  // 키를 눌렀을때(down)
  document.addEventListener("keydown", function (e) {
    keysDown[e.keyCode] = true;
    console.log("키다운캑체에 들어간 값은?", keysDown);
  });
  // 키 (누른거) 손떼었을때(up)
  document.addEventListener("keyup", function (e) {
    delete keysDown[e.keyCode];

    if (e.keyCode == 32) {
      createBullet(); // 총알 생성하는 함수
    }
  });
}

function createBullet() {
  console.log("총알 생성!");
  let b = new Bullet();
  b.init(); // class Bullet에서 정의해준 init함수 실행시킴
  console.log("새로운 총알 리스트", bulletList);
}

function createEnemy() {
  const interval = setInterval(function () {
    let e = new Enemy();
    e.init();
  }, 1500); // (호출하고싶은 함수, 시간마다-ms) , 1초 = 1000ms
}

function update() {
  if (39 in keysDown) {
    spaceshipX += 3;
  } // right
  if (37 in keysDown) {
    spaceshipX -= 3;
  } // left

  // 우주선의 좌표값이 틀 안에서만 있게 하려면
  if (spaceshipX <= 0) {
    spaceshipX = 0;
  }
  if (spaceshipX >= canvas.width - 64) {
    spaceshipX = canvas.width - 64;
  }

  // 총알의 y좌표 업데이트 하는 함수
  for (let i = 0; i < bulletList.length; i++) {
    if (bulletList[i].alive) {
      bulletList[i].update();
      bulletList[i].checkHit();
    }
  }

  // enemy 업데이트 하는 함수
  for (let i = 0; i < enemyList.length; i++) {
    enemyList[i].update();
  }
}

function render() {
  ctx.drawImage(backgroundImage, 0, 0, canvas.width, canvas.height);
  ctx.drawImage(spaceshipImage, spaceshipX, spaceshipY);
  ctx.fillText(`Score:${score}`, 20, 30); // 가, 세
  ctx.fillStyle = "white";
  ctx.font = "20px Arial";
  for (let i = 0; i < bulletList.length; i++) {
    if (bulletList[i].alive) {
      ctx.drawImage(bulletImage, bulletList[i].x, bulletList[i].y);
    }
  }

  for (let i = 0; i < enemyList.length; i++) {
    ctx.drawImage(enemyImage, enemyList[i].x, enemyList[i].y);
  }
}

function main() {
  if (!gameOver) {
    update(); // 좌표값을 업데이트하고
    render(); // 그려주고
    console.log("animation calls main function");
    requestAnimationFrame(main); // frame 여러번 계속 호출함.(자기자신계속호출시켜서 이미지가 render되도록함.)
  } else {
    ctx.drawImage(gameOverImage, 10, 100, 380, 380);
  }
}
loadImage();
setupKeyboardListener();
createEnemy();
main();

/* 방향키를 누르면 
우주선의 xy좌표가 바뀌고
다시 render 그려준다 */

/* 총알만들기
1. 스페이스바를 누르면 총알 발사
2. 총알이 발사 = 총알의 y값이 --(줄어듬), 
총알의 x값은? 스페이스를 누른 순간의 우주선의 x좌표
3. 발사된 총알들은 총알 배열에 저장을 한다.
4. 모든 총알들은 x,y좌표값이 있어야 한다.
5. 총알 배열을 가지고 render 그려준다.
*/

/* 적군만들기
1. 귀엽다. x,y,init, update
2. 적군은 위치가 랜덤하다.
3. 적군은 밑으로 내려온다.
4. 1초마다 하나씩 적군이 나온다.
5. 적군이 바닥에 닿으면 게임 오버

6. 적군이 죽는다 => 총알이 적군에게 닿는다. 
총알.y <= 적군.y and 
총알.x >= 적군.x and 총알.x <= 적군.x+너비

=> 닿았다
=> 총알이 죽게됨. 적군이 없어짐. 점수획득
*/


