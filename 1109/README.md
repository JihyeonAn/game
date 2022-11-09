3종류의 차트 
===============

**1. bar 차트**
'''
type: 'bar',
            data: {
                labels: ['넷플릭스', '웨이브', '티빙', '유튜브', '쿠팡플레이']
'''
바 형태로 차트 표현


**2. 도넛 차트**
'''
const myChart2 = new Chart(ctx2, {
            type: 'doughnut',
            data: {
                labels: ['넷플릭스', '웨이브', '티빙', '유튜브', '쿠팡플레이']
'''
도넛 형태로 차트 표현


**3. line 차트**
'''
 const ctx3 = document.getElementById('myChart3').getContext('2d');
        const myChart3 = new Chart(ctx3, {
            type: 'line',
            data: {
                labels: ['넷플릭스', '웨이브', '티빙', '유튜브', '쿠팡플레이']
'''

선 형태로 차트 표현


[github.io 주소](https://github.com/JihyeonAn/game/blob/main/1109/chart.html)
[Netlify 주소](https://app.netlify.com/sites/silly-cannoli-2aa3da/overview)

