export let cart = JSON.parse(localStorage.getItem("cart")) ?? [
  {
    productId: "e43638ce-6aa0-4b85-b27f-e1d07eb678c6",
    quantity: 2,
  },
  {
    productId: "15b6fc6f-327a-4ec4-896f-486349e85a3d",
    quantity: 1,
  },
];

function saveToStorage() {
  localStorage.setItem("cart", JSON.stringify(cart));
}

export function addToCart(productId) {
  const quantitySelect = document.querySelector(
    `.js-cart-quantity[data-product-id="${productId}"]`
  );
  const selectedQuantity = parseInt(quantitySelect.value);

  // checking if the `productId` exists in the cart
  let matchingItem;
  cart.forEach((cartItem) => {
    if (productId === cartItem.productId) {
      matchingItem = cartItem;
    }
  });

  if (matchingItem) {
    matchingItem.quantity += selectedQuantity; // add the selected count in cart
  } else {
    cart.push({
      productId,
      quantity: selectedQuantity,
    });
  }

  saveToStorage();
}

export function removeFromCart(productId) {
  const newCart = [];

  cart.forEach((cartItem) => {
    if (cartItem.productId !== productId) {
      newCart.push(cartItem);
    }
  });

  cart = newCart;

  saveToStorage();
}

export function updateCartQuantity(className) {
  // calculate cart quantity
  let cartQuantity = 0;
  cart.forEach((cartItem) => {
    cartQuantity += cartItem.quantity;
  });

  // "js-cart-quantity"
  // "js-checkout-items-count"

  // Update the inner HTML of the specified classes
  const cartQuantityElement = document.querySelector(`.js-cart-quantity`);
  const checkoutItemsCountElement = document.querySelector(
    `.js-checkout-items-count`
  );

  if (cartQuantityElement) {
    cartQuantityElement.innerHTML = cartQuantity;
  }

  if (checkoutItemsCountElement) {
    checkoutItemsCountElement.innerHTML = cartQuantity + " items";
  }
}
