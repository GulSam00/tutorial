import React, {Component} from 'react';

class Matcher extends Component {
	
	render() {
		const {name} = this.props.match.params;
		let urlParams = (new URLSearchParams(this.props.location.search.slice(1)));
		console.log(urlParams);
		const returnConponent;
			if (name === "view") {
			
			}
			else if (name === "data") {

			}
			else if (name === "bann") {
				
			}
			else {
				returnConponent = <></>;
			}
			<div>gello!</div>
	}
}

export default Matcher;