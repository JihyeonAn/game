공굴리기 게임수정
===============

**수정 사항**

> 1.배경추가

> 2.움직이는 발판생성
```C#
private IEnumerator Movement()
    {
        while (true)
        {
            Vector3 direction = (wayPoints[currentIndex].position - transform.position).normalized;

            transform.position += direction * moveSpeed * Time.deltaTime;

            if (Vector3.Distance(transform.position, wayPoints[currentIndex].position) < 0.1f)
            {
                transform.position = wayPoints[currentIndex].position;

                break;
            }
            yield return null;
        }
    }
```
> 3.점프판생성
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
> 4.텔레포트 생성
 ```C#
> private void OnTriggerEnter(Collider other)
    {
        if (other.CompareTag("Player"))
        {
            audioSource.Play();

            other.transform.position = arrivePoint.position;
        }
    }
   ```

> 5.효과음 생성

> 6.코인을 다 먹어야 통과됨

> 7.스테이지 만들기

**주소**

[github.io 주소](https://jihyeonan.github.io/game/1101/index.html)
