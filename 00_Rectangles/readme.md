# 00_Rectangles

## Introducing

* `namespace`
* C++11's `shared_ptr` and `weak_ptr`
* C++11's `auto`

## Steps

### 1. Draw a rectangle

* Set the backgound colour to white
* Draw a black rectangle to the screen (x=200,y=200,width=200,height=200)

### 2. `Rectangle` struct within a namespace `Shapes`

* Add properties `bounds` and `color` to `Rectangle`
* Add method `draw` to `Rectangle`

### 3. `vector` of `shared_ptr<Shapes::Rectangle>`

* Create a new rectangle every time the user drags

### 4. Select rectangle by hovering

* Use a `weak_ptr` to represent the rectangle underneath the mouse cursor
* Delete selected rectangle on `OF_KEY_BACKSPACE`

## Style notes

### Classes, namespaces

* Each class has its own cpp / h file pair
* Each namespace has a folder
* Class definitions start with capital letter (e.g. `Rectangle`). Instances use lower case `rectangle`.
* Minimise includes in header files. Be more generous with includes in cpp files (header files may be included by many cpp's, so including a lot there means many cpp's are affected).

### Functions

* We use `const` for functions where it makes sense now, and remove later if we need to,
* Each function definition (cpp) has `//` and 10 `-`s above it (e.g. `//----------`)

### `shared_ptr`

* Use `make_shared<TypeName>(...Constructor arguments...)` as a shorthand to make a new instance as a shared pointer.
### Other
* Create a scope `{` ... `}` between `ofPushStyle()` / `ofPopStyle()`, etc.