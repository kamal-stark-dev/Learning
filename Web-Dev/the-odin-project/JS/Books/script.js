const library = [];
let bookCounter = 373829;

function Book(title, author, pages) {
  // this.id = crypto.randomUUID();
  this.id = ++bookCounter;
  this.title = title;
  this.author = author;
  this.pages = pages;
  this.read = false;
}

Book.prototype.toggleRead = function () {
  if (this.read) this.read = false;
  else this.read = true;
};

function addBookToLibrary(title, author, pages) {
  const temp = new Book(title, author, pages);
  library.push(temp);
}

function displayBooks() {
  const shelf = document.getElementById("books");
  let html = "";
  for (const book of library) {
    html += `
      <div class="book" data-id="${book.id}">
        <h2>${book.title}</h2>
        <p>${book.author}</p>
        <p>${book.pages} pages</p>
        <p class="read-status">${book.read ? "Read" : "Not Read"}</p>
        <i class="ri-delete-bin-line remove-book"></i>
      </div>
    `;
  }
  html += `
    <div class="book div-add-book">
      <button id="add-book">Add book <i class="ri-add-large-line"></i></button>
    </div>
  `;
  shelf.innerHTML = html;

  // adding event listener to the add-book button
  const showBtn = document.getElementById("add-book");
  showBtn.addEventListener("click", () => {
    dialog.showModal();
  });

  // adding read status eventlistener to each status
  const readStatuses = document.querySelectorAll(".read-status");
  readStatuses.forEach((status_) => {
    status_.addEventListener("click", () => {
      const bookId = status_.parentElement.dataset.id;
      const idx = library.findIndex((book) => book.id == bookId);
      if (idx !== -1) {
        library[idx].toggleRead();
        displayBooks();
      }
    });
  });

  // adding event listeners to all the remove buttons
  const removeBtns = document.querySelectorAll(".remove-book");
  removeBtns.forEach((btn) => {
    btn.addEventListener("click", () => {
      const bookId = btn.parentElement.dataset.id;
      const idx = library.findIndex((book) => book.id == bookId);
      if (idx !== -1) {
        library.splice(idx, 1);
        displayBooks();
      }
    });
  });
}

addBookToLibrary("ABC", "PQR", 200);
addBookToLibrary("JKL", "XYZ", 180);
library[0].toggleRead();
displayBooks();

const dialog = document.querySelector("dialog");
const closeBtn = document.getElementById("close-dialog");

closeBtn.addEventListener("click", () => {
  dialog.close();
});

function addNewBook() {
  const title = document.getElementById("book-name").value;
  const author = document.getElementById("book-author").value;
  const pages = document.getElementById("book-pages").value;

  addBookToLibrary(title, author, pages);
  displayBooks();
}

document.querySelector("#dialog-box form").addEventListener("submit", (e) => {
  e.preventDefault();
  addNewBook();
});
