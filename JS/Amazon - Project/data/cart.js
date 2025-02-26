export const cart = [];

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
}
