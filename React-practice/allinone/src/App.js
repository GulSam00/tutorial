import logo from "./logo.svg";
import { BrowserRouter, Link, Route, Switch } from "react-router-dom";
import Table from "@material-ui/core/Table";
import TableHead from "@material-ui/core/TableHead";
import TableBody from "@material-ui/core/TableBody";
import TableRow from "@material-ui/core/TableRow";
import TableCell from "@material-ui/core/TableCell";
import Matcher from "./Matcher";
import "./App.css";

const App = () => {
  return (
    <Table>
      <BrowserRouter>
        <div className="header">
          <TableHead>
            <TableRow>
              <TableCell>
                <Link to="/bobs/view">모아보기</Link>
              </TableCell>
              <TableCell>
                <Link to="/bobs/data">조회</Link>
              </TableCell>
              <TableCell>
                <Link to="/bobs/bann">차단리스트</Link>
              </TableCell>
            </TableRow>
          </TableHead>
        </div>
        <div>
          <Switch>
            <Route exact path="/bobs/:name" component={Matcher} />
          </Switch>
        </div>
      </BrowserRouter>
    </Table>
  );
};

export default App;
