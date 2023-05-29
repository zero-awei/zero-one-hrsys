"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
function toArray(thing) {
    if (!thing) {
        return [];
    }
    else if (Array.isArray(thing)) {
        return thing;
    }
    else {
        return [thing];
    }
}
function getOptions(cliFlags, packageJsonData, tsconfigJsonData) {
    var packageJsonConfig = packageJsonData.ts || {};
    if (packageJsonConfig.include && !Array.isArray(packageJsonConfig.include)) {
        throw new Error("Expected 'ts.include' in package.json file to be an array.");
    }
    if (tsconfigJsonData.include && !Array.isArray(tsconfigJsonData.include)) {
        throw new Error("Expected 'include' in tsconfig.json file to be an array.");
    }
    var emitTSConfig = Boolean(cliFlags.emitTsconfig || (packageJsonConfig.emit && packageJsonConfig.emit.tsconfig));
    var include = packageJsonConfig.include || tsconfigJsonData.include || undefined;
    var monorepo = cliFlags.monorepo || packageJsonConfig.monorepo;
    var transformations = cliFlags.transform ? toArray(cliFlags.transform) : packageJsonConfig.transforms || [];
    var typingsDirectory = cliFlags.typingsDir || packageJsonConfig.typingsDirectory || "./typings";
    return {
        emitTSConfig: emitTSConfig,
        include: include,
        monorepo: monorepo,
        transformations: transformations,
        typingsDirectory: typingsDirectory
    };
}
exports.getOptions = getOptions;
