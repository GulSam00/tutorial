import React, {Component} from 'react'
import {withRouter} from 'react-router-dom';
import Data1 from './Data1';
import Data2 from './Data2';
import RSP from './../RSP/RSPclass';
import NumberBaseball from './../NumberBaseball/Baseball'

class GameMacher extends Component {

	render() {
		const {name} = this.props.match.params;
		let urlParams = (new URLSearchParams(this.props.location.search.slice(1)));
		console.log(this.props);
		if (name === "Data1") {
			return (
				<Data1/>
		)}
		else if (name === "Data2") {
			return (
				<Data2/>
			)}
			else if (name === "RSP") {
				return (
					<RSP/>
				)}
				else if (name === "Baseball") {
					return (
						<NumberBaseball/>
					)}
					else {
						return (
							<div>일치하는 부분이 없습니다.</div>
						)
					}
	}
}

export default GameMacher;