const path = require('path');
const webpack = require('webpack');
const refresh = require('@pmmmwh/react-refresh-webpack-plugin'); 

module.exports = {
	mode : "development", // 상용화는 production
	devtool : "eval",
	resolve : {
		extensions : [".js", ".jsx"],
	},
	
	entry : {
		app : ['./client'],
	}, // 입력
	module : {
		rules : [{
			test : /\.jsx?/,
			loader : 'babel-loader',
			options : {
				presets : [
					['@babel/preset-env', {
					targets : {
						browsers : ['> 1% in KR']
					},
					debug: true,
				}], '@babel/preset-react'
				],
				plugins : [
					'@babel/plugin-proposal-class-properties',
					'react-refresh/babel',
				],
			},
		}]
	},
	plugins: [
		new webpack.LoaderOptionsPlugin({debug : true}),
		new refresh(), 
	],
	output : {
		path : path.join(__dirname, 'dist'),
		filename : 'App.js'
	}, // 출력
	devServer : {
		publicPath : '/dist/',
		hot : true,
	} // webpack-confing.js대로 빌드하면 dist에 결과물을 메모리로 저장, 변경점을 감지한다면 그에 따라 저장한 결과물을 자동으로 수정해줌.
};