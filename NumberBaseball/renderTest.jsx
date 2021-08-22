import React, {PureComponent} from 'react';

class Test extends PureComponent {
	state = {
		counters: 0,
		array : [],
	}

	onClick = () => {
		this.setState ({
			counters: 0,
			array : [this.state.array, 1],
		});
	}

	render() {
		console.log("렌더링");
		console.log(this.state.array);
		return (
			<div>
				<button onClick={this.onClick}>클릭!</button>
				<div>{this.state.counters}</div>
			</div>
		)
	}
}

export default Test;