import React, {PureComponent, memo} from 'react';


//함수 컴포넌트

const Try = memo(({tryInfo}) => {
	return (
		<li>
			<div>{tryInfo.try}</div>
			<div>{tryInfo.result}</div>
		</li>
			)
});

/*
//클래스 컴포넌트
class Try extends PureComponent {

render() {
const { tryInfo } = this.props;
return (
	<li>
		<div>{tryInfo.try}</div>
		<div>{tryInfo.result}</div>
	</li>
		)
	}
}
 */
export default Try;