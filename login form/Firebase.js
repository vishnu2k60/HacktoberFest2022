// Import the functions you need from the SDKs you need
import { initializeApp } from "firebase/app";
// TODO: Add SDKs for Firebase products that you want to use
// https://firebase.google.com/docs/web/setup#available-libraries

// Your web app's Firebase configuration
const firebaseConfig = {
  apiKey: "AIzaSyBbXn11EFZ-B4UutkGbbvFFhddnqWFpDWc",
  authDomain: "test-app-c0aed.firebaseapp.com",
  projectId: "test-app-c0aed",
  storageBucket: "test-app-c0aed.appspot.com",
  messagingSenderId: "797893271922",
  appId: "1:797893271922:web:5fc8bade62add0ca573deb"
};

// Initialize Firebase
const app = initializeApp(firebaseConfig);
//prevent default
const preventDefault = e => e.preventDefault();

