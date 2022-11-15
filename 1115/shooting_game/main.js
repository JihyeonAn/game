// 캔버스 세팅
let canvas;
let ctx;
canvas = document.createElement("canvas");
ctx = canvas.getContext("2d");
canvas.width = 620;
canvas.height = 827;
document.body.appendChild(canvas);

let backgroundImage, spaceshipImage, bulletImage, enemyImage, gameOverImage;
let gameOver = false; // true면 게임이 끝남, false면 게임이 안끝남.
var audio2 = new Audio("fail.mp3");
let score = 0;

// 우주선 좌표
let spaceshipX = canvas.width / 2 - 30; // 우주선 높이,넓이 : 30
let spaceshipY = canvas.height - 60;

let bulletList = []; // 총알들을 저장하는 리스트
var audio = new Audio("Gun_sound.mp3");

function Bullet() {
  this.x = 0;
  this.y = 0;
  this.init = () => {
    this.x = spaceshipX + 5;
    this.y = spaceshipY - 60;
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
        this.x >= enemyList[i].x-15 &&
        this.x <= enemyList[i].x + 15
      ) {
        //총알이 죽게됨, 적군이 없어짐, 점수획득
        audio.play();
        score++;
        this.alive = false; //죽은 총알
        enemyList.splice(i, 1); // i번째에 있는거 하나를 잘라냄.
      }
    }
  };
}

function RandomValue(min, max) {
  let randomNum = Math.floor(Math.random() * (max - min + 1)) + min; 
  return randomNum;
}

let enemyList = [];
function Enemy() {
  this.x = 0;
  this.y = 0;
  this.init = () => {
    this.y = 0;
    this.x = RandomValue(0, canvas.width - 32); // 최대, 최소 받음

    enemyList.push(this);
  };
  this.update = function () {
    this.y += 1.7; // 적군의 속도 조절

    if (this.y >= canvas.height - 32) {
      gameOver = true;
      audio2.play();
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
  let b = new Bullet();
  b.init(); // class Bullet에서 정의해준 init함수 실행시킴
}

function createEnemy() {
  const interval = setInterval(function () {
    let e = new Enemy();
    e.init();
  }, 1500); // (호출하고싶은 함수, 시간마다-ms) , 1초 = 1000ms
}

function update() {
  if (39 in keysDown) {
    spaceshipX += 5;
  } // right
  if (37 in keysDown) {
    spaceshipX -= 5;
  } // left

  // 우주선의 좌표값이 틀 안에서만 있게 하려면
  if (spaceshipX <= 0) {
    spaceshipX = 0;
  }
  if (spaceshipX >= canvas.width - 60) {
    spaceshipX = canvas.width - 60;
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
    //console.log("animation calls main function");
    requestAnimationFrame(main); // frame 여러번 계속 호출함.(자기자신계속호출시켜서 이미지가 render되도록함.)
  } else {
    ctx.drawImage(gameOverImage, 30, 100, 550, 380);
  }
}
loadImage();
setupKeyboardListener();
createEnemy();
main();



