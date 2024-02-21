import React, {useRef, useState, useReducer, useEffect, useCallback} from 'react';
import Table from './Table'

const initalState = {
	winner : "",
	turn : "O",
	tableData : [
		['','',''],
		['','',''],
		['','','']],
	recentCell : [-1, -1],
};

export const SET_WINNER = "SET_WINNER";
export const CLICK_CELL = "CLICK_CELL";
export const CHANGE_TURN = "CHANGE_TURN";
export const RESET_GAME = "RESET_GAME";



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
				recentCell : [action.row, action.cell],
			}
		case CHANGE_TURN :
		return {
			...state,
			turn : state.turn === 'O' ? 'X' : 'O',
		};
		case RESET_GAME :
		return {
			...state,
			winner : "",
			turn : "O",
			tableData : [
				['','',''],
				['','',''],
				['','','']],
			recentCell : [-1, -1],
		}
		default :
			return state;
	}
}

const TicTacToe = () => {
	const [state, dispatch] = useReducer(reducer, initalState);
	const {tableData, turn, winner, recentCell} =  state;

	useEffect(() => {	
	let win = false;
	const [row, cell] = recentCell;
	if (row < 0) {
		return ;
	}
	if (tableData[row][0] === turn && tableData[row][1] === turn && tableData[row][2] === turn) {
      win = true;
    }
    if (tableData[0][cell] === turn && tableData[1][cell] === turn && tableData[2][cell] === turn) {
      win = true;
    }
    if (tableData[0][0] === turn && tableData[1][1] === turn && tableData[2][2] === turn) {
      win = true;
    }
    if (tableData[0][2] === turn && tableData[1][1] === turn && tableData[2][0] === turn) {
      win = true;
     }
	if (win) {
		dispatch({type : SET_WINNER, winner : turn});
		setTimeout(() => dispatch({type : RESET_GAME}), 1000);
	} else {
		let all = true;
		tableData.forEach((row) => {
			row.forEach((cell) => {
				if (!cell) {
					all = false;
				}
			})
		})
		if (all)
			dispatch({type : RESET_GAME});
	}
	dispatch({type:CHANGE_TURN});

}, [recentCell])

	return (
		<>
		<Table tableData={tableData} dispatch={dispatch}/>
		{winner && <div>{winner}님의 승리!</div>}
		</>
	)
}

export default TicTacToe;