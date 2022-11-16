ball.html수정
===============

**코드 분석**

> [Canvas 설정]
```html
<canvas id="canvas" width="500" height="800"></canvas>
```
> [KeyDown,KeyUp]
```html
const keyDownHandler = (e) => {
            if (e.key == "Right" || e.key == "ArrowRight") {
                right = true;
                ...
 const keyUpHandler = (e) => {
            if (e.key == "Right" || e.key == "ArrowRight") {
                right = false;
                ...
```
> [원 자동생성]
```html
let rw = Math.random() * canvas.width,
            rh = Math.random() * canvas.height;
```
> 점수 내는 방법
```html
function point() {
            if ((x <= rw + 15 && x >= rw - 15) && (y <= rh + 15 && y >= rh - 15)) {
                score++;
                rw = Math.random() * canvas.width;
                rh = Math.random() * canvas.height;
            }
```

**주소**

[github.io 주소](https://github.com/JihyeonAn/game/tree/main/1115)
[Netlify 주소](https://app.netlify.com/sites/rad-otter-c95b29/overview)
[Start 화면 참고 주소](https://dw3232.tistory.com/31)
