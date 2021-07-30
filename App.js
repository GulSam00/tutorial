import React from 'react';
import { Alert } from "react-native";
import Loading from "./Loading";
import * as Location from "expo-location";
import axios from 'axios';

const API_KEY = "d1c107c8268b24d2a0f669ea62e3aa5a"

export default class App extends React.Component {
  state = {
    isLoading: true,
  }
  async getWeather(latitude, longitude) {
    const {data} = await axios.get(`http://api.openweathermap.org/data/2.5/weather?lat=${latitude}&lon=${longitude}&APPID=${API_KEY}`);
    console.log(data);
  }
  
  async getLocation() {
    try {
      await Location.requestForegroundPermissionsAsync();

      const {coords : {latitude, longitude}} = await Location.getCurrentPositionAsync();
      this.getWeather(latitude, longitude);
      this.setState({isLoading: false});
      
    } catch (error) {
        Alert.alert("Cant find you.", "so sad");
    }

  }
  componentDidMount(){
    this.getLocation();
  }
  render() {
    const {isLoading} = this.state;

    return isLoading ? <Loading/> : null;
  }
}
