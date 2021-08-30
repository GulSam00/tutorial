import React, { Component } from 'react';
import './App.css';
import Customer from './components/Customer';
import Paper from '@material-ui/core/Paper';

import Table from '@material-ui/core/Table';
import TableHead from '@material-ui/core/TableHead';
import TableBody from '@material-ui/core/TableBody';
import TableRow from '@material-ui/core/TableRow';
import TableCell from '@material-ui/core/TableCell';

import { withStyles } from '@material-ui/core/styles';

const styles = (theme) => ({
  root: {
    width: '100%',
    marginTop: theme.spacing.unit * 3,
    overflowX: 'auto',
  },
  table: {
    minWidth: 1000,
  },
});

class App extends Component {
  state = {
    data: ['', '', ''],
  };
  addState = () => {
    this.setState((prevState) => {
      return {
        data: [...prevState.data, ''],
      };
    });
  };
  render() {
    const { classes } = this.props;
    return (
      <Paper className={classes.root}>
        <button onClick={this.addState}>버튼</button>
        <Table className={classes.table}>
          <TableHead>
            <TableRow>
              <TableCell>1</TableCell>
              <TableCell>1</TableCell>
              <TableCell>1</TableCell>
            </TableRow>
          </TableHead>
          <TableBody>
            {this.state.data.map((e) => (
              <Customer />
            ))}
          </TableBody>
        </Table>
      </Paper>
    );
  }
}

export default withStyles(styles)(App);
