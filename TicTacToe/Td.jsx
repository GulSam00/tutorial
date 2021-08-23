import React, {useCallback} from 'react';
import {CLICK_CELL, CHANGE_TURN} from "./TicTacToeFunction";

const Td = ({cellData, rowIndex, cellIndex, dispatch}) => {
  console.log(rowIndex, cellIndex);
  const onCilckTd = useCallback(() => {
    console.log(rowIndex, cellIndex);
    dispatch({type:CLICK_CELL, row:rowIndex, cell:cellIndex});
    dispatch({type:CHANGE_TURN});
  }, []);
  return (
    <td rowIndex={rowIndex} cellIndex={cellIndex} onClick={onCilckTd} cellData={cellData}>{cellData}</td>
  )
}

export default Td;
