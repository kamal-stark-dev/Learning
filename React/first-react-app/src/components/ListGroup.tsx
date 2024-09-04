import { useState } from "react";

// { items: [], heading: string }
interface Props {
  items: string[];
  heading: string;
}

function ListGroup(props: Props) {
  let [selectedIndex, setSelectedIndex] = useState(-1);

  // we have implemented it in shorter form below and removed h1 redundancy
  // if (items.length === 0)
  //   return (
  //     <>
  //       <h1>List</h1>
  //       <p>No items found!</p>
  //     </>
  //   );

  const checkNull = () => {
    // return items.length === 0 ? <p>No items found!</p> : null;
    return props.items.length === 0 && <p>No items found!</p>;
  };

  return (
    // <h1>List Group</h1>
    // The above h1 will generate an error as you can not return more than one element from a function as it is using `createElement()`
    // one thing to tackle this is by wrapping all the components in a div
    // or the recommended method will be to import and use a fragment or just use empty angle-brackets -> `<>` and `</>`

    <>
      <h1>{props.heading}</h1>
      {checkNull()}
      <ul className="list-group">
        {props.items.map((item, index) => (
          <li
            className={
              selectedIndex === index
                ? "list-group-item active"
                : "list-group-item"
            }
            key={item}
            onClick={() => setSelectedIndex(index)}
          >
            {item}
          </li>
        ))}
      </ul>
    </>
  );
}

export default ListGroup;
