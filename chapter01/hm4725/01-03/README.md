# 01-03
> - 03 설계 개선하기 (p.17~34)
> - 04 객체 지향 설계 (p.34~36)

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
Process 82611: 220 nodes malloced for 12 KB
Process 82611: 6 leaks for 144 total leaked bytes.

    6 (144 bytes) << TOTAL >>

      3 (64 bytes) ROOT LEAK: 0x145e06900 [32]
         1 (16 bytes) 0x145e068d0 [16]
         1 (16 bytes) 0x145e06940 [16]

      2 (48 bytes) ROOT LEAK: 0x145e06950 [32]
         1 (16 bytes) 0x145e068e0 [16]

      1 (32 bytes) ROOT LEAK: 0x145e06970 [32]
```