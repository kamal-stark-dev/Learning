import "./App.css";
import Home from "./pages/Home";
import { Routes, Route } from "react-router-dom";
import Favorites from "./pages/Favorites";
import NavBar from "./components/NavBar";

function App() {
  return (
    <div>
      <NavBar />
      <main className="main-content">
        <Routes>
          <Route path="/" element={<Home />} />
          <Route path="/favorites" element={<Favorites />} />
        </Routes>
      </main>
    </div>
  );
}

export default App;

/*
> Componenet -> A component is any function in JavaScript which returns some kind of JSX code.
    - they always starts with a capital letter ex: App()

`<>` -> Fragment is a placeholder which acts as a parent, it's an empty tag.

1. The first thing you should be diong when you are building your project is to look what sort of components do you need.
*/
