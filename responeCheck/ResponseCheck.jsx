import React, {Component, PureComponent, useRef, useState, memo, createRef} from 'react';

// class ResponseCheck extends PureComponent {
// 	state = {
// 		state : "waiting",
// 		message : "클릭해서 시작하세요.",
// 		result : []
// 	};	

// 	timeout;
// 	startTime;
// 	endTime;
// 	onClickScreen = () => {
// 		const {state, message, result} = this.state;
// 		if (state === "waiting") {
// 			this.setState({
// 				state : "ready",
// 				message : "초록색이 되면 클릭하세요.",
// 			});
// 			this.timeout = setTimeout(() => {
// 				this.setState({
// 					state : "now",
// 					message : "지금 클릭!"
// 				});
// 				this.startTime = new Date();
// 			}, Math.floor(Math.random() * 1000) + 2000);
// 		} else if (state == "ready") { // 성급하게 클릭
// 			clearTimeout(this.timeout);
// 			this.setState({
// 				state : "waiting",
// 				message : "성급하시군요!",
// 				result : [],
// 			})
// 		} else if (state == "now") { // 반응속도 체크
// 			this.endTime = new Date();
// 			this.setState((prevState) => {
// 				return {
// 					state : "waiting",
// 					message : "클릭해서 시작하세요.",
// 					result : [...prevState.result, this.endTime - this.startTime],
// 				} 	
// 			})
// 		}
// 	}
// 	renderAverage = () => {
// 		const {result} = this.state;
// 		console.log(result);
// 		return result.length === 0
// 		? null 
// 		: <div>평균 시간 : {result.reduce((a, c) => a + c) / result.length}ms</div>
// 	};

// 	Reset = () => {
// 		this.setState({
// 			result : [],
// 		})
// 	}
// 	render() {
// 		return (
// 			<>
// 			<div id="screen" className={this.state.state} onClick={this.onClickScreen}>
// 				{this.state.message}
// 			</div>
// 			{this.renderAverage()}
// 			<button onClick={this.Reset}>리셋</button>
// 			</>
// 		)
// 	}
// }

const ResponseCheck = () => {
	const [state, setState] = useState("waiting");
	const [message, setMessage] = useState("클릭해서 시작하세요.");
	const [result, setResult] = useState([]);
	const timeout = useRef(null);
	const startTime = useRef();
	const endTime = useRef();
	const onClickScreen = () => {
		if (state === "waiting") {
			setState("ready");
			setMessage("초록색이 되면 클릭하세요.");
			timeout.current = setTimeout(() => {
				setState("now");
				setMessage("지금 클릭!");
				startTime.current = new Date();
			}, Math.floor(Math.random() * 1000) + 2000);
		} else if (state == "ready") { // 성급하게 클릭
			clearTimeout(timeout.current);
			setState("waiting");
			setMessage("성급하셨군요!");
		} else if (state == "now") { // 반응속도 체크
			endTime.current = new Date();
			setState("waiting");
			setMessage("클릭해서 시작하세요."); 
			setResult((prevResult) =>  {
				return [...prevResult, endTime.current - startTime.current]
			});
		}
	}
	const renderAverage = () => {
		return result.length === 0
		? null 
		: <div>평균 시간 : {result.reduce((a, c) => a + c) / result.length}ms</div>
	};

	const Reset = () => {
				setResult([]);
			}
	return (
		<>
			<div id="screen" className={state} onClick={onClickScreen}>
				{message}
			</div>		
			{renderAverage()}
			<button onClick={Reset}>리셋</button>
			</>
	)
}

export default ResponseCheck;