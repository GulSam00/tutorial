const React = require('react');
const { useState, useRef } = React;

const WordRelay = () => {

  const [word, setWord] = useState('제로초');

  const [value, setValue] = useState('');
  const [answer, setAnswer] = useState('');
  const inputRef = useRef(null);

  const onSubmitForm = (e) => {  //onSubmitForm : 엔터로 정보가 전송시 실행
    e.preventDefault(); // 창이 새로고침 되는 걸 방지
    if (word[word.length - 1] === value[0]) {
      console.log( word[word.length - 1] +" == " + value[0]);
        setWord(value);
        setValue('');
        setAnswer('정답!');
        
      inputRef.current.focus();
    }
      else {
        setValue('');
        setAnswer('땡!');
        inputRef.current.focus();
      }
  
  }

  const onChangeInput = (e) => {
    setValue(e.target.value);
  }

    return (
    <>
    <div>{word}</div>
    <form onSubmit={onSubmitForm}>
      <label htmlFor="word"></label> 
      <input ref={inputRef} value={value} id="word" className="word" onChange={onChangeInput}/>
      <button>클릭!</button>
      <div>{answer}</div>
    </form>

    </>
    )}
module.exports = WordRelay;