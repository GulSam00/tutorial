import React from 'react';
import { BrowserRouter, HashRouter, Link, Route, Switch } from 'react-router-dom';
import GameMacher from './gameMacher'
const Games = () => {
	return (
		<BrowserRouter>
		<div>
			<Link to="/game/Data1?key1=10&key2=20">DATA1</Link>
			&nbsp;
			<Link to="/game/Data2?key1=100&key2=200">DATA2</Link>
			&nbsp;
			<Link to="/game/RSP?key1=1000&key2=2000">RSP</Link>
			&nbsp;
			<Link to="/game/Baseball?key1=10000&key2=20000">Baseball</Link>
			&nbsp;
		</div>

		<div>
			<Switch>
			<Route exact path="/" component={GameMacher}/>
			<Route exact path="/game/:name" component={GameMacher}/>
			</Switch>
		</div>
		</BrowserRouter>
		);
};

export default Games;