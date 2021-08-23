import React, {Component} from 'react';
import Ball from './ballClass';

function getWinNumbers() {
	console.log("getWinNumber");
	const candidate = Array(45).fill().map((v, i) => i + 1);
	const shuffle = [];
	while (candidate.length > 0) {
		shuffle.push(candidate.splice(Math.floor(Math.random() * candidate.length), 1)[0]);
	}
	const bonusNumber = shuffle[shuffle.length - 1];
	const winNumber = shuffle.slice(0, 6).sort((p , c) => p - c);
	return [...winNumber, bonusNumber];
}

class Lotto extends Component {
	state = {
		winNumber : getWinNumbers(), // 숫자의 배열
		winBalls : [], // 앞의 6개
		bonus : null,
		redo : false,
	}
	timeouts = [];

	runTimeout = () => {
		console.log("runTimeout");
		const {winNumber} = this.state;
		for (let i = 0; i < winNumber.length - 1; i++) {
			this.timeouts[i] = setTimeout(() => {
				this.setState((prevState) => {
					return {
						winBalls : [...prevState.winBalls, winNumber[i]],
					}
				})
		}, (i + 1) * 1000);
	}
	this.timeouts[6] = setTimeout(() => {
		this.setState({
			bonus : winNumber[6],
			redo : true,
		})
	}, 7000);
	}
	componentDidMount() {
		console.log("componentDidMount");
		this.runTimeout();
}

	componentDidUpdate(prevProps, prevState) {
		console.log("componentDidUpdate");

		if (this.state.winBalls.length === 0)
		{
			this.runTimeout();
		}
	} 

	componentWillUnmount() {

		this.timeouts.forEach((v) => 
		clearTimeout(v));
	}

	onClickRedo = () => {
		console.log("onClickRedo");

		this.setState({
			winNumber : getWinNumbers(), // 숫자의 배열
			winBalls : [], // 앞의 6개
			bonus : null,
			redo : false,
		});
		this.timeouts = [];
	}

	render() {
		const {winBalls, bonus, redo} = this.state;
		return (
			<>
			 <div>당첨 숫자</div>
      <div id="결과창">
        {winBalls.map((v) => <Ball key={v} number={v} />)}
      </div>
      <div>보너스!</div>
      {bonus && <Ball key={bonus} number={bonus}/>}
      {redo && <button onClick={this.onClickRedo}>한 번 더!</button>}
			</>
		)
	}
}

export default Lotto;