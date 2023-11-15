# 01-reference
객체 동적할당 대신 **필드**와 **레퍼런스**를 활용
```
💡 main.cc::DECORATOR_PATTERN을 0으로 바꾸면,
   객체 동기화가 되지 않아 테스트 통과에 실패하게 됩니다.
```

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
Process 82708: 213 nodes malloced for 12 KB
Process 82708: 0 leaks for 0 total leaked bytes.
```