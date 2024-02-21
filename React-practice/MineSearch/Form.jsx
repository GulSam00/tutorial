import React, {useState, useCallback, useContext, memo} from 'react'
import {TableContext, START_GAME} from './MineSearch'


const Form = memo(() => {	const [row, setRow] = useState(10);
	const [cell, setCell] = useState(10);
	const [mine, setMine] = useState(20);
	const {dispatch} = useContext(TableContext);
	const onChangeRow = useCallback((e) => {
		setRow(e.target.value);
	}, [])
	const onChangeCell = useCallback((e) => {
		setCell(e.target.value);

	}, [])
	const onChangeMine = useCallback((e) => {
		setMine(e.target.value);
	}, [])
	const onClickButton = () => {
		dispatch({type: START_GAME, row, cell, mine},
			[row, cell, mine]);
	} //useCallback을 사용하니 row,cell,mine 값을 변경해도 적용이 안됨.

	return (
		<div>
			<input type="number" placeholder="세로" value={row} onChange={onChangeRow}/>
			<input type="number" placeholder="가로" value={cell} onChange={onChangeCell}/>
			<input type="number" placeholder="지뢰" value={mine} onChange={onChangeMine}/>
			<button onClick={onClickButton}>시작</button>
		</div>
	)
})

export default Form;