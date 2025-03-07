import { products } from "../data/products.js";
import { cart, addToCart, updateCartQuantity } from "../data/cart.js";
import { formatCurrency } from "./utils/money.js";

// This is how the data looks like (Array of Objects)
/*
const products = [
  {
    id: "e43638ce-6aa0-4b85-b27f-e1d07eb678c6",
    image: "images/products/athletic-cotton-socks-6-pairs.jpg",
    name: "Black and Gray Athletic Cotton Socks - 6 Pairs",
    rating: {
      stars: 4.5,
      count: 87,
    },
    priceCents: 1090,
    keywords: ["socks", "sports", "apparel"],
  },
  {
    id: "15b6fc6f-327a-4ec4-896f-486349e85a3d",
    image: "images/products/intermediate-composite-basketball.jpg",
    name: "Intermediate Size Basketball",
    rating: {
      stars: 4,
      count: 127,
    },
    priceCents: 2095,
    keywords: ["sports", "basketballs"],
  },
];
*/

function productHTML(product) {
  return `
    <div class="product-container">
      <div class="product-image-container">
      <img
          class="product-image"
          src="${product.image}"
      />
      </div>

      <div class="product-name limit-text-to-2-lines">
          ${product.name}
      </div>

      <div class="product-rating-container">
          <img
              class="product-rating-stars"
              src="images/ratings/rating-${product.rating.stars * 10}.png"
          />
          <div class="product-rating-count link-primary">
              ${product.rating.count}
          </div>
      </div>

      <div class="product-price">
          $${formatCurrency(product.priceCents)}
      </div>

      <div class="product-quantity-container">
      <select class="js-cart-quantity" data-product-id="${product.id}">
          <option selected value="1">1</option>
          <option value="2">2</option>
          <option value="3">3</option>
          <option value="4">4</option>
          <option value="5">5</option>
          <option value="6">6</option>
          <option value="7">7</option>
          <option value="8">8</option>
          <option value="9">9</option>
          <option value="10">10</option>
      </select>
      </div>

      <div class="product-spacer"></div>

      <div class="added-to-cart" data-product-id="${product.id}">
      <img src="images/icons/checkmark.png" />
      Added
      </div>

      <button
        class="add-to-cart-button button-primary js-add-to-cart"
        data-product-id="${product.id}"
      >
          Add to Cart
      </button>
  </div>
  `;
}

let productsHTML = "";
products.forEach((product) => {
  productsHTML += productHTML(product);
});

// console.log(productsHTML);
document.querySelector(".js-products-grid").innerHTML = productsHTML;

updateCartQuantity();

function handleAddedToCart(timeoutId, productId) {
  // this function sets added-to-cart text to the appropriate button
  const addedToCart = document.querySelector(
    `.added-to-cart[data-product-id="${productId}"]`
  );
  addedToCart.classList.add("selected");

  // Clear the previous timeout if it exists
  if (timeoutId) {
    clearTimeout(timeoutId);
  }
  timeoutId = setTimeout(() => {
    addedToCart.classList.remove("selected");
  }, 2000);
}

document.querySelectorAll(".js-add-to-cart").forEach((button) => {
  button.addEventListener("click", () => {
    const { productId } = button.dataset;

    addToCart(productId);
    updateCartQuantity();
    let timeoutId;
    handleAddedToCart(timeoutId, productId);
  });
});
