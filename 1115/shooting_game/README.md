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
>


**주소**

[github.io 주소](https://github.com/JihyeonAn/game/tree/main/1115)
[Netlify 주소](https://app.netlify.com/sites/rad-otter-c95b29/overview)
[Start 화면 참고 주소](https://dw3232.tistory.com/31)
