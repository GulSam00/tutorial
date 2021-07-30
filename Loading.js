import React from 'react';
import { StyleSheet, Text, View } from 'react-native';


function Loading(){
    return <View style={styles.container}>
       <Text style={styles.text}>Get the weather</Text> 
    </View>
}

const styles = StyleSheet.create({
    container: {
        flex : 1,
        justifyContent : 'flex-end',
        paddingHorizontal : 30,
        paddingVertical : 100,
        backgroundColor : "red"
    },
    text : {
        color : "#2c2c2c",
        fontSize : 20
    }
})

export default Loading;