공굴리기 게임수정
===============

**수정 사항**

> [배경추가]
```C#


```
> [움직이는 발판생성]
```html
<table class="uk-table uk-table-striped">…</table>
```
> [점프판생성]
```C#
 private void OnCollisionEnter(Collision collision)
    {
        if (collision.transform.CompareTag("Player"))
        {
            audioSource.Play();

            collision.transform.GetComponent<Movement3D>().MoveTo(direction, accelForce);
        }
    }
```
> [텔레포트 생성]

> [효과음 생성]
> [코인을 다 먹어야 통과됨]
> [스테이지 만들기]

**주소**

[github.io 주소](https://jihyeonan.github.io/game/1101/index.html)
