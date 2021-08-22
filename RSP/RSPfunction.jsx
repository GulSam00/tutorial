import React, {useRef, useState, useEffect, memo} from 'react';

const rspCoord = {
	바위 : "0",
	가위 : "-142px",
	보 : '-284px',
}

const scores = {
	가위 : 1,
	바위 : 0,
	보 : -1,
}

const computerChoice = (imgCoord) => {
	
	return Object.entries(rspCoord).find((v) => {
		return v[1] === imgCoord;
	})[0];
}

const RSP = () => {
	const [result, setResult] = useState("");
	const [imgCoord, setImgCoord] = useState("0");
	const [score, setScore] = useState(0);
	const interval = useRef(null);
	
	useEffect(() => { //componentDidMount, componentDidUpdate 역할
		interval.current = setInterval(changeHand, 300);
		return () => { // componentWillUnmount 역할
			clearInterval(interval.current);
		}		
	}, [imgCoord]);

	const changeHand = () => {
			if (imgCoord === rspCoord.바위) {
				setImgCoord(rspCoord.가위);
			} else if (imgCoord === rspCoord.가위) {
				setImgCoord(rspCoord.보);
			} else if (imgCoord === rspCoord.보) {
				setImgCoord(rspCoord.바위);
			}
	}
	const onClickBtn = (choice) => (e) => {
		console.log(e);
		clearInterval(interval.current);
		const myScore = scores[choice];
		const cquScore = scores[computerChoice(imgCoord)];
		const diff = myScore - cquScore;
		if (diff === 0) {
			setResult("비겼습니다.");
		} else if ([-1, 2].includes(diff)) {
			setResult("이겼습니다!");
			setScore((prevScore) => {
				return (prevScore + 1);
			})
		} else {
			setResult("졌습니다...");
			setScore((prevScore) => {
				return (prevScore - 1);
			})
		}
		setTimeout(() => {
			interval.current = setInterval(changeHand, 100);
		}, 2000);
	}
		return (
			<>
			<div id="computer" style={{ background: `url(https://en.pimg.jp/023/182/267/1/23182267.jpg) ${imgCoord} 0` }} />
			<div>
			  <button id="rock" className="btn" onClick={onClickBtn('바위')}>바위</button>
			  <button id="scissor" className="btn" onClick={onClickBtn('가위')}>가위</button>
			  <button id="paper" className="btn" onClick={onClickBtn('보')}>보</button>
			</div>
			<div>{result}</div>
			<div>현재 {score}점</div>
		  </>
		)
}

export default RSP;