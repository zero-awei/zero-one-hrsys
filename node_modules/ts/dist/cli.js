#!/usr/bin/env node
"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
var __importStar = (this && this.__importStar) || function (mod) {
    if (mod && mod.__esModule) return mod;
    var result = {};
    if (mod != null) for (var k in mod) if (Object.hasOwnProperty.call(mod, k)) result[k] = mod[k];
    result["default"] = mod;
    return result;
};
Object.defineProperty(exports, "__esModule", { value: true });
var meow_1 = __importDefault(require("meow"));
var commands = __importStar(require("./commands/index"));
var helpText = "\nUsage\n  General usage\n  $ ts <command> [<...options>]\n\n  Compile project in current directory\n  $ ts [build]\n\n  Compile with altered options\n  $ ts --target es2018 src/**/*.ts\n\n  Create tsconfig.json\n  $ ts --emit-tsconfig [<...options>]\n\n  Show this help text\n  $ ts --help\n\nCommands\n  build                 Compile a TypeScript project. Default command.\n  compile               Alias of \"build\".\n  search                Search for a type declarations package on npm.\n\nGeneral options\n  --help                Print this help.\n  --version             Print version.\n\nSee <https://github.com/andywer/ts> for details.\n";
var cli = meow_1.default(helpText, {
    autoHelp: false,
    flags: {
        "declaration": {
            type: "boolean"
        },
        "emit-tsconfig": {
            type: "boolean"
        },
        "emit-tslint": {
            type: "boolean"
        },
        "monorepo": {
            type: "boolean"
        },
        "no-strict": {
            type: "boolean"
        },
        "out-dir": {
            alias: "o"
        },
        "skip-lib-check": {
            type: "boolean"
        },
        "target": {
            alias: "t"
        },
        "watch": {
            alias: "w",
            type: "boolean"
        }
    }
});
var firstArgument = process.argv[2];
var commandName = firstArgument && firstArgument.match(/^[a-z]+$/) ? firstArgument : null;
if (cli.input[0] === commandName) {
    cli.input.shift();
}
var command = commands[commandName ? commandName.toLowerCase() : "build"];
if (commandName && !command) {
    console.error("Command not found: " + commandName.toLowerCase());
    cli.showHelp();
    process.exit(1);
}
if (cli.flags.help) {
    if (commandName) {
        console.error(command.help);
    }
    else {
        cli.showHelp();
    }
    process.exit(0);
}
else if (cli.flags.version) {
    cli.showVersion();
    process.exit(0);
}
command.run(cli).catch(function (error) {
    console.error(error);
    process.exit(1);
});
