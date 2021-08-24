import React, {useContext, memo} from 'react';
import Tr from './Tr';
import { TableContext } from './MineSearch';

const Table = memo(() => {
  console.log("Table render");
  const {tableData} = useContext(TableContext);
  console.log(tableData.length);
  return (
    <table>
      {Array(tableData.length).fill().map((tr, i) => <Tr rowIndex={i}/>)}
    </table>
  );
});

export default Table;
