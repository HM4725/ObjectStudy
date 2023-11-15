# 01-smart-pointer
**스마트 포인터**를 활용하여, 안정적으로 객체를 회수

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
##### 결과: 메모리 누수 X
```
leaks Report Version: 4.0
Process 83274: 213 nodes malloced for 12 KB
Process 83274: 0 leaks for 0 total leaked bytes.
```