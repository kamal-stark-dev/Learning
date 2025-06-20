import "./App.css";
import Home from "./pages/Home";
import MovieCard from "./components/MovieCard";

function App() {
  const movieNumber = 1;

  return (
    <>
      <Home />
    </>
  );
}

export default App;

/*
> Componenet -> A component is any function in JavaScript which returns some kind of JSX code.
    - they always starts with a capital letter ex: App()

`<>` -> Fragment is a placeholder which acts as a parent, it's an empty tag.

1. The first thing you should be diong when you are building your project is to look what sort of components do you need.
*/
