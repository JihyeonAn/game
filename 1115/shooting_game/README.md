start.html & main.js
===============

**코드 분석**

> **시작 화면 구성**
```html
#wrapper{
    width:700px;
    height:500px;
    border:5px solid yellow;
    margin: auto;
    text-align: center;
} 
```
> **반짝거리도록 표현**
```html
function blink(){
    let vision = (flag)? "none":"block";
    document.querySelector("p").style.display= vision;
    flag=!flag;
}
window.addEventListener("load", function(){
    init();
    setInterval("blink()",500);
});
```
> **슈팅게임 연결**
```html
let flag=true;
function init(){
    document.querySelector("button").addEventListener("click", function(){
        location.href="shooting_game.html";
    });
```
> **이미지 삽입**
```js
function loadImage() {
  backgroundImage = new Image();
  backgroundImage.src = "images/backgroundImage.png";
```
> **총알 생성**
```js
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
  ```
  > **적 생성**
  ```js
  let enemyList = [];
function Enemy() {
  this.x = 0;
  this.y = 0;
  this.init = () => {
    this.y = 0;
    this.x = RandomValue(0, canvas.width - 32); // 최대, 최소 받음

    enemyList.push(this);
  };
  ```
  > **점수내는 방법**
  ```js
  for (let i = 0; i < enemyList.length; i++) {
      if (
        this.y <= enemyList[i].y &&
        this.x >= enemyList[i].x-15 &&
        this.x <= enemyList[i].x + 15
      ) 
   ...
  ```
  > **게임종료 **
  ```js
  if (this.y >= canvas.height - 32) {
      gameOver = true;
      audio2.play();
  ```


**주소**

[github.io 주소](https://github.com/JihyeonAn/game/tree/main/1115)
[Netlify 주소](https://app.netlify.com/sites/rad-otter-c95b29/overview)
