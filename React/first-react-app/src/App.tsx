import ListGroup from "./components/ListGroup";

function App() {
  let characters = [
    "Naruto",
    "Sasuke",
    "Kakashi",
    "Jiraya",
    "Itachi",
    "Minato",
  ];

  let cities = ["London", "New York", "Tokyo", "Delhi", "Banglore", "Paris"];

  return (
    <>
      <ListGroup items={characters} heading="Naruto Top Favorites" />
      <ListGroup items={cities} heading="Famous Cities" />
    </>
  );
}

export default App;
