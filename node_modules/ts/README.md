# ts

The CLI that TypeScript deserves.

✨  Simple project setup<br/>
📦  Modern defaults<br/>
🏷  Painless custom type declarations<br/>
🔍  Search for type packages on npm<br/>
👌  Selectively override options on the command line (yes, `tsc` does not allow that)<br />


## Installation

Locally:

```sh
$ npm install --save-dev typescript ts
```

Globally:

```sh
$ npm install --global typescript ts
```


## Quick start

Run the TypeScript compiler with `ts` default best practice options:

```sh
npx ts --out-dir <path> <...entrypoint files>
```

Compiling using `ts` does not require a `tsconfig.json` file, but `ts` will act according to its options if found.

If your source files are in `src/` and you want to write the output files to `dist/`, you don't even need to set anything:

```sh
npx ts
```

Run with `--emit-tsconfig` to create a `tsconfig.json` file.

```sh
# Write ts default options into tsconfig.json
npm ts --emit-tsconfig
```
```sh
# Options: create declaration files, target runtime ES2016
npm ts --declaration --emit-tsconfig --target es2016
```


## Usage

```
Usage
  General usage
  $ ts <command> [<...options>]

  Compile project in current directory
  $ ts [build]

  Compile with altered options
  $ ts --target es2018 src/**/*.ts

  Create tsconfig.json
  $ ts --emit-tsconfig [<...options>]

  Show this help text
  $ ts --help

Commands
  build                 Compile a TypeScript project. Default command.
  compile               Alias of "build".
  search                Search for a type declarations package on npm.

General options
  --help                Print this help.
  --version             Print version.

See <https://github.com/andywer/ts> for details.
```


## Monorepo support

Run `ts` with `--monorepo` or set the `monorepo` option in the `package.json` file (see below).

This will make TypeScript look for packages not only in `./node_modules/`, but also in `../../node_modules/` (the monorepo root directory's `node_modules`). It will also look for type declaration packages and custom local type declarations in the monorepo root.


## Custom type package support

By default `ts` will not only load type declaration from `@types/*` packages, but also from `@<username>/types-*`.

That allows you to easily publish your custom type declarations to npm under the scope of your npm user name without going through all the overhead of Definitely Typed.

Use the `ts search` command to find type declaration packages on npm:

```sh
$ ts search koa
# Will list all packages matching "@types/*" | "@*/types-*" and "koa"
```


## Local type declarations

`ts` makes it particularly easy to use local typings for third party modules.

By default all `typings/**/*.d.ts` files will be loaded. Use the `--typings-directory` argument to change the search path from `typings/` to something else.


## Usage with other tools

Most users will also use `tslint`, maybe the webpack `ts-loader` or have an IDE that relies on knowing the TypeScript compiler options. You want them to behave the same way that `ts` does.

Easy: Just run `ts --emit-tsconfig` to write all the compiler options into a `tsconfig.json` file. Other tools will pick it up and use the same configuration.


## Defaults

In contrast to `tsc` behavior, `ts` lets you override options set in the `package.json` or `tsconfig.json` selectively using command line arguments. Yes, you heard right, `tsc` will ignore your `tsconfig.json` once you set a single option via command line 🤦‍

This is a `tsconfig.json` that resembles the `ts` default options:

```json
{
  "compilerOptions": {
    "esModuleInterop": true,
    "lib": ["es2015"],
    "module": "commonjs",
    "moduleResolution": "node",
    "newLine": "lf",
    "target": "es5",
    "outDir": "<output directory>",
    "strict": true
  },
  "include": [
    "<entrypoint file path>"
  ]
}
```


## Configuration in `package.json`

You can also set all `ts` options and TypeScript `compilerOptions` in your `package.json`:

```ts
{
  "ts": {
    "compilerOptions": {
      /* Any compiler options */
    },
    "include": [
      /* Source files (entrypoints) */
    ],
    "monorepo": boolean,
    "transforms": [
      /* Transformations (package name or local path) */
    ],
    "typingsDirectory": "./typings"
  }
}
```

**Experimental:** Allows you to `.gitignore` your `tsconfig.json` file altogether.


## License

MIT
