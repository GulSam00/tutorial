import React from 'react';
import Try  from './Try.js';

/*

const Baseball = () => {

  const [answer, setAnswer] = useState('');
  const [value, setValue] = useState('');
  const [result, setResult] = useState('');
  
  const inputRef = useRef(null);

  const onSubmitForm = (e) => {  //onSubmitForm : 엔터로 정보가 전송시 실행
    e.preventDefault(); // 창이 새로고침 되는 걸 방지
    if (parseInt(value) == 0) {
      setResult("테스트용");
      inputRef.current.focus();
      
    }
      else {
        setResult("테스트용");
        inputRef.current.focus();
      }
  
  }
  const onRefInput = (e) => {
    inputRef = e; //html의 input을 이 리액트 컴포넌트에서 input으로 불러올 수 있게 된다.
  }

  const onChangeInput = (e) => {
    setValue(e.target.value);
  }

    return (
    <>
    <h1>숫자야구 {result}</h1>
    <form onSubmit={onSubmitForm}>
      <label htmlFor="word">답을 입력하세요.</label> 
      <input ref={inputRef} value={value} id="word" className="word" onChange={onChangeInput}/>
      <button>클릭!</button>
      <div>{answer}</div>
    </form>

    </>
    )}
*/
function getNumbers() { //숫자 4개를 랜덤하게
  const numberList = [1, 2, 3, 4, 5, 6, 7, 8, 9];
  const array = [];
  for (let i = 0; i < 4; i++) {
    const selected = numberList.splice(Math.floor(Math.random() * (9 - i)), 1)[0];
    array.push(selected);
  }
  console.log(array);
  return array;
}

class Baseball extends React.Component {
  state = {
    result : "",
    value : "",
    answer : getNumbers(),
    tries : [],
  };
  onSubmitForm = (e) => {
    e.preventDefault();
    console.log(this.state.answer.join('') + ' ' + this.state.value);
    if (this.state.answer.join('') === this.state.value)
    {
      this.setState({
        result : "홈런!",
        tries : [...this.state.tries, {try: this.state.value, result:"홈런!"}],
        value : "",
      })
      console.log("정답!");
    }
    else
    {
      
    }
     
  };
  onChangeInput = (e) => {
      this.setState({value : e.target.value});
  };

 
  fruits = [{name : '사과', taste : '달다'}, 
      {name : '배', taste : '시원하다'}, 
      {name : '포도', taste : '시다'}];
  render() {
    return (
    <>
    <h1>숫자야구</h1>
    <form onSubmit={this.onSubmitForm}>
    <input maxLength={4} value={this.state.value} onChange={this.onChangeInput}/>
    </form>
    <div>시도 : {this.state.tries.length}</div>
    <ul>
    {this.fruits.map((e, index) => {return(<Try key={index} value={e} index={index}/>)})}

    </ul>

   
    </>
    )}
}

export default Baseball;