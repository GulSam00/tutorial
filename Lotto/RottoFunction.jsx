import React, {useRef, useState, useEffect, useMemo, useCallback} from 'react';
import Ball from './ballClass';

function getWinNumbers() {
	console.log("getWinNumber");
	const candidate = Array(45).fill().map((v, i) => i + 1);
	const shuffle = [];
	while (candidate.length > 0) {
		shuffle.push(candidate.splice(Math.floor(Math.random() * candidate.length), 1)[0]);
	}
	const bonusNumber = shuffle[shuffle.length - 1];
	const winNumbers = shuffle.slice(0, 6).sort((p , c) => p - c);
	return [...winNumbers, bonusNumber];
}

const Lotto = () => {
	const [winBalls, setWinBalls] = useState([]);
	const lottoNumbers = useMemo(() => getWinNumbers(), [winBalls]);
	const [winNumbers, setWinNumber] = useState(lottoNumbers);
	const [bonus, setBonus] = useState(null);
	const [redo, setRedo] = useState(false);
	const timeouts = useRef([]);

	useEffect(() => {
		console.log("useEffect");
		runTimeout();
		return () => {
			timeouts.current.forEach((v) => {
				clearTimeout(v);
			})
		}
	}, [timeouts.current])

	const runTimeout = () => {
		for (let i = 0; i < winNumbers.length - 1; i++) {
			timeouts.current[i] = setTimeout(() => {
			setWinBalls((prevWinBalls) => [...prevWinBalls, winNumbers[i]]);
			}, (i + 1) * 1000);
	}
	timeouts.current[6] = setTimeout(() => {
		setBonus(winNumbers[6]);
		setRedo(true);	
		}, 7000);
	}

	const onClickRedo = useCallback(() => {
		console.log(winNumbers);
		console.log("onClickRedo");
			setWinNumber(getWinNumbers());
			setWinBalls([])
			setBonus(null);
			setRedo(false);
		timeouts.current = [];
	}, [winNumbers]);

		return (
			<>
			 <div>당첨 숫자</div>
      <div id="결과창">
        {winBalls.map((v) => <Ball key={v} number={v} />)}
      </div>
      <div>보너스!</div>
      {bonus && <Ball key={bonus} number={bonus}/>}
      {redo && <button onClick={onClickRedo}>한 번 더!</button>}
			</>
		)

}

export default Lotto;