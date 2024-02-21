import React, {useCallback, memo}  from 'react';
import {CLICK_CELL} from "./TicTacToeFunction";

const Td = memo(({cellData, rowIndex, cellIndex, dispatch}) => {
  console.log("Td render");
  const onCilckTd = useCallback(() => {
    if (cellData) {
      return ;
    }
    dispatch({type:CLICK_CELL, row:rowIndex, cell:cellIndex});
  }, [cellData]);
  return (
    <td rowIndex={rowIndex} cellIndex={cellIndex} onClick={onCilckTd} cellData={cellData}>{cellData}</td>
  )
});

export default Td;
