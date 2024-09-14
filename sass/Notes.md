# SASS

> What is SCSS?
> It's a css extention language which gives you css powers, the browsers can't read sass that's why we need a compiler to convert it into vanila css.

## Variables in SASS

In normal css variables are defined like this -

```css
:root {
  --background-color: #333;
  --card-margin: 4rem;
}

body {
  background: var(--background-color);
}
```

But in scss we define variables like this -

```scss
$text-color: #fff;
$bg-color: #222;

body {
  background: $bg-color;
  color: $text-color;
}
```

Which will be compiled into css having fixed values of the colors rather than the variable value.

```css
body {
  background: #222;
  color: #fff;
}
```

## Maps in SCSS -

Maps are similar to arrays & dictionaries in python, to create it use -

```scss
$font-sizes: (
  "small": 0.6rem,
  "regular": 1.2rem,
  "large": 2.4rem,
  "title": 4.8rem,
);

h1 {
  font-size: map-get($font-sizes, title);
}
span {
  font-size: map-get($font-sizes, regular);
}
```

> We use `map-get` to select a value from a map, it takes map-name and key value.

This gets converted to the following css -

```css
h1 {
  font-size: 4.8rem;
}
span {
  font-size: 1.2rem;
}
```

## We can also indent elements in SCSS

```scss
.main {
  width: 75%;
  margin: 0 auto;

  p {
    font-size: 1.2rem;

    &:hover {
      color: #00ff00;
    }
  }
}
```

We won't have to use `.main p` for the same.
