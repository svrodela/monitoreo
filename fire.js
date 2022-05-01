var firebase = require('firebase')
// change lines below with your own Firebase snippets!
var config = {
  /*apiKey: "AIzaSyDSLRypcYx2yHSqpVXJMBrzYw1xAHZtgYI",
  authDomain: "test-iot-esp.firebaseapp.com",
  databaseURL: "https://test-iot-esp.firebaseio.com",
  projectId: "test-iot-esp",
  storageBucket: "test-iot-esp.appspot.com",
  messagingSenderId: "467772798973"*/
  apiKey: "AIzaSyBeZZte8NoLdzj5eYd26QnICidQoP85B8c",
  authDomain: "region676-e21b8.firebaseapp.com",
  databaseURL: "https://region676-e21b8.firebaseio.com",
  projectId: "region676-e21b8",
  storageBucket: "region676-e21b8.appspot.com",
  messagingSenderId: "764985918459",
  appId: "1:764985918459:web:4c38f754eda41b3476c15e",
  measurementId: "G-W1QHXKKH5R"
};
const fire = firebase.initializeApp(config);
module.exports = fire;