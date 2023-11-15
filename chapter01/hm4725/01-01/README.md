# 01-01
> - 01 티켓 판매 애플리케이션 구현하기 (p.9~14)
> - 02 무엇이 문제인가 (p.14~17)

### 1. 빌드
```sh
make
```
### 2. 테스트 실행
```sh
./run.exe
```
### 3. 메모리 누수 체크
#### MacOS 환경
```sh
leaks --atExit -- ./run.exe
```
##### 결과: 메모리 누수 O
```
leaks Report Version: 4.0
Process 82459: 220 nodes malloced for 12 KB
Process 82459: 6 leaks for 144 total leaked bytes.

    6 (144 bytes) << TOTAL >>

      3 (64 bytes) ROOT LEAK: 0x154606900 [32]
         1 (16 bytes) 0x1546068d0 [16]
         1 (16 bytes) 0x154606940 [16]

      2 (48 bytes) ROOT LEAK: 0x154606950 [32]
         1 (16 bytes) 0x1546068e0 [16]

      1 (32 bytes) ROOT LEAK: 0x154606970 [32]
```