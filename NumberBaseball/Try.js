import React, {Component} from 'react';

class Try extends Component {
	render(){
return (
<li id={this.props.value.name} key={this.props.value.name} >
 	 {this.props.index} {this.props.value.name}는 {this.props.value.taste} 
</li>
		)
	}
}

export default Try;