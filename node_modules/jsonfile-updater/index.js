'use strict';

var fs = require('fs')

function Updater(jsonFilePath) {
  this.jsonFilePath = jsonFilePath
  return this
}

Updater.prototype.add = function(property, value, cb) {
  var jsonFilePath = this.jsonFilePath
  if (!cb) {
    return new Promise((resolve, reject) => {
      addProperty(resolve, reject)
    })
  } else {
    addProperty(cb)
  }

  function addProperty(resolve, reject) {
    let isPromise = false
    let cb = resolve
    if (reject) isPromise = true

    fs.access(jsonFilePath, function(err) {
      if (err) {
        if (isPromise) return reject(err)
        return cb(err)
      }
      fs.readFile(jsonFilePath, 'utf8', function(err, fileContent) {

        if (err) {
          if (isPromise) return reject(err)
          return cb(err)
        }

        var pkg = JSON.parse(fileContent)
        var inputProperties = property.split('.')
        var propertyCursor = pkg
        var propertyPath = ''

        for (var i = 0; i < inputProperties.length; i++) {
          var subProperty = inputProperties[i]
          propertyPath += '.' + subProperty
          if (i === inputProperties.length - 1) {
            if (typeof(propertyCursor[subProperty]) !== 'undefined') {
              var err = new Error('Property "' + propertyPath + '" already defined')
              if (isPromise) reject(err)
              else return cb(err)
            }
            propertyCursor[subProperty] = value
          } else {
            if (typeof(propertyCursor[subProperty]) === 'undefined') { propertyCursor[subProperty] = {} }
          }
          propertyCursor = propertyCursor[subProperty]
        }

        var updatedPackage = JSON.stringify(pkg, null, 2)
        fs.writeFile(jsonFilePath, updatedPackage, function(err) {
          if (err) {
            if (isPromise) return reject(err)
            return cb(err)
          } else {
            if (isPromise) return resolve()
            return cb()
          }
        })
      })
    })
  }
}

Updater.prototype.set = function(property, value, cb) {
  var jsonFilePath = this.jsonFilePath
  if (!cb) {
    return new Promise((resolve, reject) => {
      setProperty(resolve, reject)
    })
  } else {
    setProperty(cb)
  }

  function setProperty(resolve, reject) {
    let isPromise = false
    let cb = resolve
    if (reject) isPromise = true

    fs.access(jsonFilePath, function(err) {
      if (err) {
        if (isPromise) return reject(err)
        return cb(err)
      }

      fs.readFile(jsonFilePath, 'utf8', function(err, fileContent) {
        if (err) {
          if (isPromise) return reject(err)
          return cb(err)
        }

        var pkg = JSON.parse(fileContent)

        var inputProperties = property.split('.')
        var propertyCursor = pkg
        var propertyPath = ''

        for (var i = 0; i < inputProperties.length; i++) {
          var subProperty = inputProperties[i]
          propertyPath += '.' + subProperty
          if (i === inputProperties.length - 1) {
            if (!(subProperty in propertyCursor)) {
              var err = new Error('Property "' + propertyPath + '" not defined')
              if (isPromise) reject(err)
              else return cb(err)
            }

            try {
              if (!areSameDataType(propertyCursor[subProperty], value)) {
                var err = new Error('Mismatched data type')
                if (isPromise) reject(err)
                else return cb(err)
              } else {
                propertyCursor[subProperty] = value
              }
            } catch(err) {
              if (isPromise) reject(err)
              else return cb(err)
            }

          } else {
            propertyCursor = propertyCursor[subProperty]
          }
        }

        var updatedPackage = JSON.stringify(pkg, null, 2)
        fs.writeFile(jsonFilePath, updatedPackage, function(err) {
          if (err) {
            if (isPromise) return reject(err)
            return cb(err)
          } else {
            if (isPromise) return resolve()
            return cb()
          }
        })
      })
    })
  }
}

Updater.prototype.append = function(property, value, preserve, cb) {
  if (typeof(preserve) === 'function') {
    cb = preserve
    preserve = false
  }

  var jsonFilePath = this.jsonFilePath

  if (!cb) {
    return new Promise((resolve, reject) => {
      appendProperty(resolve, reject)
    })
  } else {
    appendProperty(cb)
  }

  function appendProperty(resolve, reject) {

    let isPromise = false
    let cb = resolve
    if (reject) isPromise = true

    fs.access(jsonFilePath, function(err) {
      if (err) {
        if (isPromise) return reject(err)
        return cb(err)
      }
      fs.readFile(jsonFilePath, 'utf8', function(err, fileContent) {
        if (err) {
          if (isPromise) return reject(err)
          return cb(err)
        }

        var pkg = JSON.parse(fileContent)

        var inputProperties = property.split('.')
        var propertyCursor = pkg
        var propertyPath = ''

        for (var i = 0; i < inputProperties.length; i++) {
          var subProperty = inputProperties[i]
          propertyPath += '.' + subProperty
          if (i === inputProperties.length - 1) {
            if (!(subProperty in propertyCursor)) {
              var err = new Error('Property "' + propertyPath + '" not defined')
              if (isPromise) reject(err)
              else return cb(err)
            }
            var currentValue = propertyCursor[subProperty]

            try {
              if (areBooleanAndBoolean(currentValue, value) || areNumberAndNumber(currentValue, value)) {
                var err = new Error('Cannot append')
                if (isPromise) reject(err)
                else return cb(err)
              } else if (!preserve && !areArrayAndValid(currentValue, value) && !areSameDataType(currentValue, value)) {
                var err = new Error('Mismatched data type')
                if (isPromise) reject(err)
                else return cb(err)
              } else {
                propertyCursor[subProperty] = getAppendedValues(propertyCursor[subProperty], value, preserve)
              }
            } catch(err) {
              if (isPromise) reject(err)
              else return cb(err)
            }

          } else {
            propertyCursor = propertyCursor[subProperty]
          }
        }

        var updatedPackage = JSON.stringify(pkg, null, 2)
        fs.writeFile(jsonFilePath, updatedPackage, function(err) {
          if (err) {
            if (isPromise) return reject(err)
            return cb(err)
          } else {
            if (isPromise) return resolve()
            return cb()
          }
        })
      })
    })
  }
}

Updater.prototype.delete = function(properties, cb) {
  var jsonFilePath = this.jsonFilePath
  if (!cb) {
    return new Promise((resolve, reject) => {
      deleteProperty(resolve, reject)
    })
  } else {
    deleteProperty(cb)
  }

  function deleteProperty(resolve, reject) {
    let isPromise = false
    let cb = resolve
    if (reject) isPromise = true

    fs.access(jsonFilePath, function(err) {
      if (err) {
        if (isPromise) return reject(err)
        return cb(err)
      }
      fs.readFile(jsonFilePath, 'utf8', function(err, fileContent) {
        if (err) {
          if (isPromise) return reject(err)
          return cb(err)
        }

        var pkg = JSON.parse(fileContent)
        var propertyCursor = pkg
        var propertyPath = ''

        var propertiesArray = []
        if (!Array.isArray(properties)) { propertiesArray.push(properties) }
        else propertiesArray = properties
        for (var i = 0; i < propertiesArray.length; i++) {
          var property = propertiesArray[i]
          var inputProperties = property.split('.')

          for (var j = 0; j < inputProperties.length; j++) {
            var subProperty = inputProperties[j]
            propertyPath += '.' + subProperty
            if (!(subProperty in propertyCursor)) {
              var err = new Error('Property "' + propertyPath + '" not defined')
              if (isPromise) reject(err)
              else return cb(err)
            }
            if (j === inputProperties.length - 1) {
              propertyCursor[subProperty] = undefined
            } else {
              propertyCursor = propertyCursor[subProperty]
            }
          }

          propertyCursor = pkg
          propertyPath = ''

        }

        var updatedPackage = JSON.stringify(pkg, null, 2)
        fs.writeFile(jsonFilePath, updatedPackage, function(err) {
          if (err) {
            if (isPromise) return reject(err)
            return cb(err)
          } else {
            if (isPromise) return resolve()
            return cb()
          }
        })
      })
    })
  }
}

Updater.prototype.remove = Updater.prototype.delete

function areBooleanAndBoolean(target, input) {
  if (typeof(target) === 'boolean' && typeof(input) === 'boolean') {
    return true
  } else { return false }
}

function areNumberAndNumber(target, input) {
  if (typeof(target) === 'number' && typeof(input) === 'number') {
    return true
  } else { return false }
}

function areArrayAndValid(target, input) {
  if (Array.isArray(target)) {
    if (typeof(input) === 'string' || typeof(input) === 'number') {
      return true
    } else { return false }
  } else { return false }
}

function areSameDataType(current, input) {
  if (Object.getPrototypeOf(current) === Object.getPrototypeOf(input)) {
    return true
  } else { return false }
}

function getAppendedValues(targetProperty, value, preserve) {
  var formattedValues = value
  if (typeof targetProperty === 'object') {
    if (Array.isArray(targetProperty)) {
      if (!Array.isArray(value)) {
        formattedValues = [value]
      }
      if (preserve === true) {
        targetProperty.push(value)
        formattedValues = targetProperty
      } else {
        formattedValues = targetProperty.concat(formattedValues)
      }

    } else {
      formattedValues = Object.assign(value, targetProperty)
    }
  } else if (typeof targetProperty === 'string') {
    formattedValues = targetProperty + value
  }
  return formattedValues
}

module.exports = function(jsonFilePath) {
  return new Updater(jsonFilePath)
}
