# jsonfile-updater

Node module for programmatically updating `package.json` and other `.json` files.

**NOTE**: This package does not create JSON files, it can only edit existing valid JSON files. A file with just `{}`
is all you need to get started.

`jsonfile-updater` enforces strict typing. Meaning, once a property of a certain type is added in the JSON file, it can be
overwritten or set a new value with the same type only.

Supported types are: boolean, string, number, array, and object. Functions are not supported.

## Usage

### Instantiation

```js
var updater = require('jsonfile-updater')
```

Further examples will be referring to the `updater` object created in the code above.

If you want to try out the examples, include the following code in your file.

```js
var fs = require('fs')
function getParsedPackage() {
  return JSON.parse(fs.readFileSync('./settings.json'))
}
```

The `jsonfile-updater` methods support both callback and promise. If you omit the callback parameter,
they return a promise, which can greatly simplify the code when used with [async](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Statements/async_function)-[await](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/await).

### Adding properties

**`add(property, value[, callback])`**

Using the `add()` instance method, you can add new properties. If you try to add a property that aleady exists, the module
will return an error. If you want to overwrite an existing property use `set()` or `append()`.

Adding a string-type property:

_Callback_

```js
updater('./settings.json').add('time', 'now', function(err) {
  if (err) return console.log(err)
  var pkg = getParsedPackage()
  console.log(pkg.time === 'now') // true
})
```

_Promise_

```js
updater('./settings.json').add('time', 'now')
.then(() => {
  var pkg = getParsedPackage()
  console.log(pkg.time === 'now') // true
}, reason => console.log(reason))
```

Adding an array-type property:

```js
updater('./settings.json').add('tags', ['nodejs', 'javascript'], function(err) {
  if (err) return console.log(err)
  var pkg = getParsedPackage()
  console.log(pkg.tags)
})
```

Adding an object-type property:

```js
updater('./settings.json').add('dependencies', { a: '1.2.1', b: '2.0.0'}, function(err) {
  if (err) return console.log(err)
  var pkg = getParsedPackage()
  console.log(pkg.dependencies)
})
```

You can add a sub-property using the dot notation:

```js
updater('./settings.json').add('author.age', 100, function(err) {
  if (err) return console.log(err)
  var pkg = getParsedPackage()
  console.log(pkg.author.age) // 100
})
```

### Updating properties

There are two methods for updating existing properties: `set()` for overwriting an existing value, `append()` for
adding additional data to an existing value.

**`set(property, value[, callback])`**

Using the `set()` method, you can overwrite existing properties. If you try to update a property does not exist,
the module will return an error. The new value should be the same as the old value's data type.

_Callback_

```js
updater('./settings.json').set('license', 'FREE', function(err) {
  if (err) return console.log(err)
  var pkg = getParsedPackage()
  console.log(pkg.license)
})
```

_Promise_

```js
updater('./settings.json').set('license', 'FREE')
.then(() => {
  var pkg = getParsedPackage()
  console.log(pkg.license)
}, reason => console.log(reason))
```

```js
updater('./settings.json').set('tags', 'cool', function(err) {
  if (err) return console.log(err)
  var pkg = getParsedPackage()
  console.log(pkg.tags.includes('cool')) // true
})
```

```js
updater('./settings.json').update('author', { 'username': 'hacksparrow' }, function(err) {
  if (err) return console.log(err)
  var pkg = getParsedPackage()
  console.log(pkg.author)
})
```

You can target a sub-property using the dot notation:

```js
updater('./settings.json').update('author.age', 200, function(err) {
  if (err) return console.log(err)
  var pkg = getParsedPackage()
  console.log(pkg.author.age) // 200
})
```

**`append(property, value[, preserve][, callback])`**

Using the `append()` method, you can append items to an existing value. If you try to update a property does not exist,
the module will return an error. `append()` does not work for all data types and work differently on different data types.

1. Booleans cannot be appended to anything
2. A string can be appended only to string or array (pushed)
3. A number can be appended only to an array (pushed)
4. An array can be appended only to another array (concatenated by default)
5. An object can be appended only to an array (pushed) or another object (merged)

When an array is append to an array, the "appendee" will be concatened to the "appender". To preserve the array of the
"appendee", and push it to the "appender", specify the `preserve` option when calling `append`.

Appending a string to an array:

_Callback_
```js
updater('./settings.json').append('tags', 'cool', function(err) {
  if (err) return console.log(err)
  var pkg = getParsedPackage()
  console.log(pkg.tags)
})
```

_Promise_
```js
updater('./settings.json').append('tags', 'cool')
.then(() => {
  var pkg = getParsedPackage()
  console.log(pkg.tags)
}, reason => console.log(reason))
```

Appending a preserved array to an array:

```js
updater('./settings.json').append('tags', ['cool', 'new'], true, function(err) {
  if (err) return console.log(err)
  var pkg = getParsedPackage()
  console.log(pkg.tags)
})
```

For more examples, refer [/test/test.js](/test/test.js).

### Deleting properties

**`delete(property|[properties ...][, callback])`**

Using the `delete()` method, you can delete existing properties. If you try to delete a property that does not exist,
the module will return an error.

FYI: `delete()` is also aliased as `remove()`.

Deleting a single property:

_Callback_
```js
updater('./settings.json').delete('name', function(err) {
  if (err) return console.log(err)
  var pkg = getParsedPackage()
  console.log(pkg)
})
```

_Promise_
```js
updater('./settings.json').delete('name')
.then(() => {
  var pkg = getParsedPackage()
  console.log(pkg)
}, reason => console.log(reason))
```

Deleting multiple properties:

```js
updater('./settings.json').delete(['name', 'version'], function(err) {
  if (err) return console.log(err)
  var pkg = getParsedPackage()
  console.log(pkg)
})
```

You can target a sub-property using the dot notation:

```js
updater('./settings.json').delete('author.age', function(err) {
  if (err) return console.log(err)
  var pkg = getParsedPackage()
  console.log(pkg.author.age) // undefined
})
```

## LICENSE

[MIT](LICENSE)
