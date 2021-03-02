## Git

* 버전관리 프로그램.
* 과거의 버전으로 돌아가는 것이 가능하다.
* 여러 사람이 프로젝트를 진행하며 버전을 공유하고 불러오는 등 유용한 기능을 제공한다.

## github

* git을 통해 만든 소스코드를 온라인 상에 배포해서 협업을 할 수 있게 만든 사이트.
* 오픈소스이기에 공공재와도 같은 위상을 가지고 있다.
* 깃을 통해 github의 소스코드를 다운할 수 있다.

## 커밋

* 파일 및 폴더의 추가/변경 사항을 저장소에 기록
* https://backlog.com/git-tutorial/kr/img/post/intro/capture_intro1_3_1.png
* 이전 커밋 상태부터 현재 상태까지의 변경 이력이 기록된 커밋(혹은 리비전)이 만들어짐.
* 커밋은 이력을 남기는 중요한 작업이기 때문에 커밋 버튼을 누를땐 커밋 메시지를 필수로 입력해야 함.
    - 메시지는 명료하고 이해하기 쉽게 남겨야 본인 뿐만 아니라 다른 사람이 커밋 이력을 확인하기 쉽다. 
    - 권장 가이드 라인   
        - 1번째 줄 : 커밋 내의 변경 내용을 요약
        - 2번째 줄 : 빈 칸
        - 3번째 줄 : 변경한 이유

## branch

* 

## Git의 영역

▶ Git의 4가지 영역
1) Working Directory (작업 트리)

    - 실제 프로젝트 디렉토리

    - .git 이력과 관련 정보가 저장 된 .git을 제외한 모든 영역

    - 실제 코드의 추가, 수정, 삭제 작업이 이루어지는 영역

2) Index (Staging Area)

    - Working Directory에서 Repository로 정보 저장 전 준비 영역

    - 파일 상태를 기록, 스테이징 한다고 표현 한다.

    - .git/index 파일로 관리된다.

    - 3.1) git add : Working Directory 에서 Index 영역으로 정보가 저장됨.

    - 3.2) git commit : Index영역에서 Repository로 정보가 저장됨.

     

3) Repository (저장소)

    - 파일, 폴더를 변경 이력별로 저장해 두는 곳

    - .git 디렉토리내 존재하며 2가지로 나뉜다.

    - 2.1) Local Repository : 개인 PC에 파일이 저장되는 개인 저장소

    - 2.2) Remote Repository : 원격 저장소 전용 서버에서 관리되며, 여러 사람들과 같이 공유도 가능한 저장소

 

4) Stash

    - 위의 3가지 영역과 다른 별개의 임시 영역

    - 임시적으로 작업사항을 저장해두고 나중에 꺼내올 수 있다.

출처: https://goddaehee.tistory.com/217?category=381481 [갓대희의 작은공간]

## 문법

### 기본 문법

* cd [경로]
    - change directory의 약자, 파일 이동을 할 수 있다.
    - cd만 입력하면 linux directory로 이동한다.

* git init : 깃 저장소를 초기화. 
    - 저장소나 디렉토리 안에서 이 명령을 실행하기 전까지는 일반 폴더에 불과. 
    - 이것을 입력한 후에야 추가적인 깃 명령어들을 줄 수 있다.

* git help : 그럼 21개의 가장 많이 사용하는 깃 명령어들이 나타난다.
    - git help [명령어]
        - 해당 명령어에 대한 좀 더 자세한 설명이 나온다.

* git status : 저장소 상태를 체크. 
    - 어떤 파일이 저장소 안에 있는지, 커밋이 필요한 변경사항이 있는지, 현재 저장소의 어떤 브랜치에서 작업하고 있는지 등을 볼 수 있다.


* git remote add origin <원격 서버 주소> : 원격 저장소에 로컬 저장소를 연결한다. 

* git add : 깃의 임시 저장소 "스냅샷"에 파일들을 추가한다.
    - `git add -A`로 변경된 모든 파일을 add할 수 있다.
    - 이것 만으로는 저장소에 새 파일들을 추가할 순 없다. 
    - git commit 명령어를 필요로 한다.


* git commit : 저장소의 "스냅샷"을 찍어 새로운 버전을 만든다.
    - `git commit -m [주석]`
        - `-m`은 명령어의 다음 부분을 메세지로 남긴다는 뜻이다.
    - 깃의 가장 중요한 명령어이다. 

* git clone : 원격 저장소의 저장소를 내 local에서 이용할 수 있게 그대로 복사해 가져온다.
    - `git clone [원격저장소 주소]`

* git push : 로컬 저장소에서 작업한 커밋들을 원격 저장소에 업로드한다. 
    - `git push [원격 저장소 이름(보통 origin)]`[저장소의 브랜치(보통 master or main)]
    - 깃허브에서 온라인으로 볼 수 있다. 

* git pull : 원격 저장소의 최신 버전을 받아올 수 있다.
    - `git push [원격 저장소 이름(보통 origin)]` [저장소의 브랜치(보통 master or main)]
    - 로컬 저장소에서 작업할 때, 깃허브로부터 최신 변경사항을 다운로드할 수 있다.

* git log : 커밋 내역을 확인할 수 있다.

* git branch : 새로운 커밋 타임라인을 만든다.
    - `git branch [브랜치 이름]`
    - 평행 세계와 비슷한 개념
    - 여러 협업자와 작업할 때, 여러 버전을 관리하고 싶을 때 유용하다.

* git checkout : 다른 브랜치로 이동할 수 있다.
    - `git checkout [브랜치 이름]`
    만약 master 브랜치를 들여다 보고 싶으면, git checkout master를 사용할 수 있다.

* git merge : master 브랜치로 다른 브랜치를 병합한다.   
    - `git merge [병합할 브랜치]`
    - 변경사항이 중복되면 오류가 발생한다.

---

### 삭제 (Index(Staging Area에서))

* git rm
    - `git rm [] [삭제할 파일 명]`
    - --cached : Index에 추가된 파일을 staging area에서 제외(working directory의 파일은 유지)

    - -f, --force : 삭제하려는 파일의 내용이 브랜치 끝 부분에서의 내용과 다를 경우 강제 삭제

    - --ignore-unmatch : 삭제하려는 파일이 없을 때 발생하는 에러 무시

### 설정 

* $ git config --global alias.[단축키] [명령어]
    - 단축키 설정



출처: https://goddaehee.tistory.com/217?category=381481 [갓대희의 작은공간]

## 용어

* Repository : 저장소를 의미하며, 저장소는 히스토리, 태그, 소스의 가지치기 혹은 branch에 따라 버전을 저장한다. 저장소를 통해 작업자가 변경한 모든 히스토리를 확인 할 수 있다.

* Working Tree : 저장소를 어느 한 시점을 바라보는 작업자의 현재 시점이다.

* Staging Area : 저장소에 커밋하기 전에 커밋을 준비하는 위치이다.

* Commit : 현재 변경된 작업 상태를 점검을 마치면 확정하고 저장소에 저장하는 작업이다.

* Head : 현재 작업중인 Branch를 가리키는 것이다.

* Branch : 가지 또는 분기점을 의미하며, 작업을 할때에 현재 상태를 복사하여 Branch에서 작업을 한 후에 완전하다 싶을때 Merge를 하여 작업을 한다.

* Merge : 다른 Branch의 내용을 현재 Branch로 가져와 합치는 작업을 의미한다.


## 사용법

* https://hees-dev.tistory.com/40
* https://goddaehee.tistory.com/217?category=381481
* https://backlog.com/git-tutorial/kr/intro/intro1_1.html
* https://rogerdudler.github.io/git-guide/index.ko.html
* https://www.youtube.com/watch?v=FXDjmsiv8fI
* https://backlog.com/git-tutorial/kr/

## 질문

* push 니 pull이니가 정확히 무엇을 업데이트하는 거지? branch? 커밋? 디렉토리 전체