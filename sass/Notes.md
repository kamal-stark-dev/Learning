# SASS

> What is SCSS?
> It's a css extention language which gives you css powers, the browsers can't read sass that's why we need a compiler to convert it into vanila css.

## Variables in SASS

In normal css _variables_ are defined like this -

```css
:root {
  --background-color: #333;
  --card-margin: 4rem;
}

body {
  background: var(--background-color);
}
```

But in **scss** we define _variables_ like this -

```scss
$text-color: #fff;
$bg-color: #222;

body {
  background: $bg-color;
  color: $text-color;
}
```

Which will be _compiled_ into css having fixed values of the colors rather than the variable value.

```css
body {
  background: #222;
  color: #fff;
}
```

## Maps in SCSS -

Maps are similar to _arrays & dictionaries_ in python, to create it use -

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

> We use `map-get` to select a value from a map, it takes _map-name_ and _key value_.

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

## Use of `&` and `#{&}` in SASS -

In SASS you use `&` to refer to parent element -

```scss
.main {
  margin: 0 auto;
  width: 75%;

  & p {
    font-size: 1.2rem;
  }
}
```

which translates to the following css -

```css
.main {
  margin: 0 auto;
  width: 75%;
}

.main p {
  font-size: 1.2rem;
}
```

Also suppose you have a class `.main` and a child class element `.main__paragraph`, then you can use the following.

```scss
// use of `interpolation`

.main {
  width: 75%;
  margin: 0 auto;

  #{&}__paragraph {
    color: #00ffff;
  }
}
```

which is similar to the following scss -

```scss
.main {
  width: 75%;
  margin: 0 auto;

  .main .main__paragraph {
    color: #00ffff;
  }
}
```

## Partials in SCSS -

to create a **_partial scss_** file you need to add a `_` before the scss file name and that _won't get compiled_ to css. These are used to import css in another scss files.

ex: inside a `_resets.scss` file -

```scss
body {
  margin: 0;
  padding: 0;
  box-sizing: border-box;
}
```

inside `main.scss` file -

```scss
@import "./resets";
```

> Notice we didn't have to use the `_` or the `.scss` extenstion while importing.

Similarly you can create a `_variables.scss` file for storing your variables.

## Functions in SCSS

Functions are coding blocks which takes some input and then return some value after processing it.

Let's create a function which makes `map-get` a little easier to use -

```scss
@function size($size) {
  @return map-get($font-sizes, $size);
}

// using a function

h1 {
  font-size: size(title);
  // ==> font-size: map-get($font-sizes, title); ==> font-size: 3.6rem;
}
```

## Mixins -

Mixins are similar to functions are let's look at its use case through an example -

```scss
@mixin flexCenter {
  display: flex;
  align-items: center;
  justify-content: center;
}

.main {
  @include flexCenter;
}
```

we can also pass arguments to a mixin, ex - `@mixin flexCenter($direction)`, we can also use mixin to add light and dark modes.

## Extend

If you have an element which have the same css as another element with few more modifications to it then you can use the `@extend` to skip writing the common css.

```scss
.para1 {
  font-size: 2rem;
  text-transform: uppercase;
  color: yellow;

  &:hover {
    color: orange;
  }
}

.para2 {
  @extend .para1;

  color: pink;
}
```

## Math Operations

To perform mathematical operations in css we needed to use `calc()` function but in scss you can do it directly.

```scss
.main {
  width: 80% - 20%;
  height: calc(80% - 20%);
}
```

The above code will compile to -

```css
.main {
  width: 60%;
  height: calc(80% - 20%);
}
```

The direct approach will give you the value in css but the `calc()` one will be the same in css.

---

So, The basics of **SASS** is done which includes things like **_variables, nested rules, mixins and functions_**.
