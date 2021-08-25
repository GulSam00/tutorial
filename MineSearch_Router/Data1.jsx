import React, {useState} from 'react';

const Data1 = () => {
	const [a, setA] = useState(1);
	return (
		<div>I'm Data1 {a}</div>
	)
}

export default Data1;