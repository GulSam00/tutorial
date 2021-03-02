# shell

* shell은 명령어 처리기. (CLI 명령을 해석하는 소프트웨어, terminal과 비슷)
* 운영체제 상에서 다양한 운영 체제 기능과 서비스를 구현하는 인터페이스를 제공하는 프로그램.
    - 사람이 컴퓨터에게 어떤 일을 시킬 때 쓰는 프로그램 같은 개념

## shell script

* 텍스트 형식으로 저장되는 프로그램.
* 한 줄씩 순차적으로 읽어 실행되도록 작성되있다.
* shell을 사용하여 컴퓨터에 시킬 명령을 텍스트로 작성하여 실행시키는 것

### sh
* 쉘의 한 종류
* 초기의 유닉스 쉘로 태어났다는 뜻인 Bourne shell의 줄임말.
* 1977년에 발표
* 프롬프트: $

### bash
* 쉘의 한 종류
* Bourne-agin shell 줄임말.
* 1987년 브라이언 폭스에 의해 탄생.
* sh와 대부분 호환.
* 프롬프트: #

### zbash

* 쉘의 한 종류 
* bash, ksh, tcsh 등 일부 기능을 포함하고 개선한 확장형 쉘.
* bash보다 command promt가 낫다.
* 사용하기 편리. (자동완성 지원)
* 프롬프트: %

---

## 문법

* https://blog.gaerae.com/2015/01/bash-hello-world.html?m=1

### 파일 생성 및 권한 부여
* touch [파일 이름].sh
    - 파일 생성
* vim [파일 이름].sh
    - vim으로 쉘 스크립트 파일 열기
* chmod +x [파일 이름].sh
    - 실행 권한 부여

### 작성 및 실행

* #!/bin/bash
    - 최상단에 꼭 써야만 shell 작동 가능

* ./[쉘스크립트 파일명]
    - 파일 실행

### 출력

```bash
#!/usr/bin/env bash
echo "hello world"
printf "hello world"
printf "%s %s" hello world
```

* `printf` 역할을 하는 `echo`
* 자동 줄바꿈

### 주석

* `#`

### 함수

```bash
string_test() {
    echo "string test"
}

function string_test2() {
    echo "string test 2"
    echo "인자값: ${@}"
}
string_test
string_test2

# 함수에 인자값 전달하기(공백의로 뛰어서 2개의 인자값을 넘김)
string_test2 "hello" "world"
```

* 형식은 다른 언어와 차이는 없다. 
* function는 생략해도 된다.
* 함수 명을 쓰면 함수가 호출. 
    - 호출 코드가 함수 코드보다 반드시 뒤에 있어야 된다. 함수 코드 보다 앞에서 호출 시 오류가 발생.

### 변수

```bash
#!/bin/bash

# shell script variable
test="abc"
num=100

# variable usage
echo ${test}
echo ${num}
echo "${test}"
echo "${num}"

# local variable
local local_val="local one"

# If variable default_value is not set, set it to "example default value" and assign again.
default_value=${default_value:="example default value"}
```

* =를 이용해서 선언하고 $를 이용해서 사용한다.
* =는 공백 없이 붙여써야한다.
* 자료형이 존재하지 않는다.
* 지역변수에는 local을 붙인다.
* {}는 parameter expansion으로 $와 함께 감싼 부분에 변수를 대입해준다.
    - (https://superuser.com/questions/935374/difference-between-and-in-shell-script) 여러 표현 방법을 통해 다양하게 사용이 가능하다.
* 변수가 선언되지 않았을때 default_value=${default_value:="example default value"}처럼 기본값을 사용하도록 설정 가능하다.
* ""로 감싸서 사용하면 더 안전. 
    - 공백도 포함해서 값을 이용하기 때문

```bash
test=1234
echo "This is $test5678" # "This is "

echo "This is ${test}5678" # "This is 12345678"
```

* 만약 {}(parameter expansion)을 사용하지 않으면 아래와 같은 경우에 변수 test가 아닌 변수 test5678을 불러오게 된다.

```bash
blank=" "
if [ ${blank} == " " ]
then
        echo "blank test"
fi
```

* 만약 ""로 감싸지 않으면 아래와 같은 조건문에서 unary operator expected라는 오류가 생길 수 있다.
    - 치환을 하는 형태이기 때문에 아래의 식이 if [ == " " ]로 바뀌기 때문.

### 배열

```bash
#!/bin/bash

arr_test_string=("abc" "def" "ghi" "jkl")
echo "${arr_test_string[2]}"

arr_test_char=('a' 'b' 'b')
echo "${arr_test_char[0]}"

arr_test_num=(1 2 3 100 10000)
echo "${arr_test_num[3]}"

echo "${arr_test_num[@]}"
```

* 배열이름=(원소1 원소2 ...)의 형태로 선언
* 배열의 인덱스는 0부터 시작
* 배열이름[@]는 배열의 모든 원소를 의미합니다.

```bash
#!/bin/bash

arr_test_string=("abc" "def" "ghi" "jkl")

arr_test_string+=("mno")
arr_test_string+=("pqr" "stu")

for i in ${arr_test_string[@]}; do
	echo $i
done

arr_test_string=(1 2 3 4 5)

arr_test_string+=(6)
arr_test_string+=(7 8)

for i in ${arr_test_string[@]}; do
	echo $i
done
```

* `+=` 연산자로 원소 추가

```sh
#!/bin/bash

arr_test=(1 2 3)
remove_element=(3)

arr_test=( "${arr_test[@]/$remove_element}" )

for i in ${arr_test[@]}; do
	echo $i
done


arr_test=("abc" "def" "ghi")
remove_element=("ghi")

arr_test=( "${arr_test[@]/$remove_element}" )

for i in ${arr_test[@]}; do
	echo $i
done

# !!! Be careful when you delete like below !!!
# Use second method in this case

arr_test=("abc" "def" "defghi")
remove_element=("def")

arr_test=( "${arr_test[@]/$remove_element}" )

for i in ${arr_test[@]}; do
	echo $i
done
```

```sh
#!/bin/bash

arr_test=("abc" "def" "defghi")
remove_element=("def")

# Get index of array
echo ${!arr_test[@]}

for i in ${!arr_test[@]}; do
	if [ ${arr_test[i]} = ${remove_element} ]; then
		# Use unset
		unset arr_test[i]
	fi
done

for i in ${arr_test[@]}; do
	echo $i
done
```

* `/`를 사용해 해당 문자열 부분이 있으면 삭제, 삭제하고자 하는 문자나 문자열이 포함되어있는 부분을 모두 삭제합니다.
* `unset`을 이용해 삭제하는 것을 권고한다.

### 조건문

```sh
#!/bin/bash

# Numeric if statement
test_num=5

if [ "${test_num}" -eq 2 ]; then
	echo "number is 2"
elif [ "${test_num}" -eq 3 ]; then
	echo "number is 3"
else
	echo "number is not 2 or 3"
fi

# Numeric if statement
test_num=5

if (( ${test_num} > 3 )); then
	echo "number is greater than 3"
else
	echo "number is not greater than 3"
fi

# String if statement
test_str="test"

if [ "${test_str}" = "test" ]; then
	echo "test_str is test"
else
	echo "test_str is not test"
fi
```

* `if [ 조건 ]; then ... elif [ 조건 ]; then ... else` 사용
* `if (( 산술 연산 )); then ... elif (( 산술 연산 )); then ... else`
* 연산자 : https://wiki.kldp.org/HOWTO/html/Adv-Bash-Scr-HOWTO/comparison-ops.html

### 반복문

```bash
#!/bin/bash

cnt=0
while (( "${cnt}" < 5 )); do
    echo "${cnt}"
    (( cnt = "${cnt}" + 1 )) # 숫자와 변수의 연산은 (())가 필요합니다.
done
```

### for 문

```bash
#!/bin/bash

arr_num=(1 2 3 4 5 6 7)

# 배열에 @는 모든 원소를 뜻합니다.
for i in ${arr_num[@]}; do
    printf $i
done
echo

for (( i = 0; i < 10; i++)); do
    printf $i
done
echo
```