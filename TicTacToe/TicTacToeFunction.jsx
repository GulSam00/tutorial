import React, {useRef, useState, useReducer, useCallback} from 'react';
import Table from './Table'

const initalState = {
	winner : "",
	turn : "O",
	tableData : [
		['','',''],
		['','',''],
		['','','']],
};

export const SET_WINNER = "SET_WINNER";
export const CLICK_CELL = "CLICK_CELL";
export const CHANGE_TURN = "CHANGE_TURN";


const reducer = (state, action) => {
	switch(action.type){
		case SET_WINNER :
			return {
				...state,
				winner: action.winner,
		}
		case CLICK_CELL : 
		const newTableData = [...state.tableData];
		newTableData[action.row] = [...state.tableData[action.row]];
		newTableData[action.row][action.cell] = state.turn; //O턴이냐, X턴이냐
		console.log(state.tableData);
			return {
				...state,
				tableData: newTableData,
			}
		case CHANGE_TURN :
		return {
			...state,
			turn : state.turn === 'O' ? 'X' : 'O',
		};
	}
}

const TicTacToe = () => {
	const [state, dispatch] = useReducer(reducer, initalState);

	return (
		<>
		<Table tableData={state.tableData} dispatch={dispatch}/>
		{state.winner && <div>{state.winner}님의 승리</div>}
		</>
	)
}

export default TicTacToe;