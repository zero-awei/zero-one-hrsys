'use strict';

const assert = require('assert')
const fs = require('fs')
const path = require('path')
const updater = require('../')
const srcSettingsPath = path.join(__dirname, 'settings.json')
const destSettingsPath = path.join(__dirname, 'test.settings.json')

describe('jsonfile-updater promise', function() {

  beforeEach(function(done) {
    fs.createReadStream(srcSettingsPath).pipe(fs.createWriteStream(destSettingsPath));
    done()
  })

  afterEach(function(done) {
    fs.unlink(destSettingsPath, done)
  })

  describe('.add()', function() {

    it('should throw if a property is aleady defined', function(done) {
      updater(destSettingsPath).add('author', 'Hage Yaapa')
      .then(() => {}, reason => done())
    })

    it('should add a boolean property', function(done) {
      updater(destSettingsPath).add('published', false)
      .then(() => {
        var pkg = JSON.parse(fs.readFileSync(destSettingsPath))
        assert.equal(false, pkg.published)
        done()
      })
    })

    it('should add a string property', function(done) {
      updater(destSettingsPath).add('time', 'now')
      .then(() => {
        var pkg = JSON.parse(fs.readFileSync(destSettingsPath))
        assert.equal('now', pkg.time)
        done()
      })
    })

    it('should add an array property', function(done) {
      updater(destSettingsPath).add('numbers', [1, 2, 3])
      .then(() => {
        var pkg = JSON.parse(fs.readFileSync(destSettingsPath))
        assert.equal(3, pkg.numbers.length)
        assert.equal(3, pkg.numbers[2])
        done()
      })
    })

    it('should add an object property', function(done) {
      updater(destSettingsPath).add('compound', {
        'one': '4.14.1',
        'two': [1, 2, 3],
        'three': {
          'a': 'a',
          'b': 'b'
        }
      })
      .then(() => {
        var pkg = JSON.parse(fs.readFileSync(destSettingsPath))
        assert.equal('4.14.1', pkg.compound.one)
        assert.equal(1, pkg.compound.two[0])
        assert.equal('a', pkg.compound.three.a)
        done()
      })
    })

    describe('dot selector', function() {

      it('should throw if a property is aleady defined', function(done) {
        updater(destSettingsPath).add('author.name', 'Yaapa').
        then(() => {}, err => done())
      })

      it('should add a boolean property', function(done) {
        updater(destSettingsPath).add('author.cool', true).
        then(() => {
          var pkg = JSON.parse(fs.readFileSync(destSettingsPath))
          assert.equal(true, pkg.author.cool)
          done()
        })
      })

      it('should add a string property', function(done) {
        updater(destSettingsPath).add('time.is', 'now')
        .then(() => {
          var pkg = JSON.parse(fs.readFileSync(destSettingsPath))
          assert.equal('now', pkg.time.is)
          done()
        })
      })

      it('should add an array property', function(done) {
        updater(destSettingsPath).add('numbers.prime.odd', [1, 3, 5, 7])
        .then(() => {
          var pkg = JSON.parse(fs.readFileSync(destSettingsPath))
          assert.equal(4, pkg.numbers.prime.odd.length)
          assert.equal(7, pkg.numbers.prime.odd[3])
          done()
        })
      })

      it('should add an object property', function(done) {
        updater(destSettingsPath).add('earth.india.karnataka', {
          'capital': 'Bengaluru'
        }).then(() => {
          var pkg = JSON.parse(fs.readFileSync(destSettingsPath))
          assert.equal('Bengaluru', pkg.earth.india.karnataka.capital)
          done()
        })
      })

    })
  })

  describe('.set()', function() {

    it('should throw if a property is not defined', function(done) {
      updater(destSettingsPath).set('random', '')
      .then(() => {}, reason => done())
    })

    it('should throw on data type mismatch', function(done) {
      updater(destSettingsPath).set('license', 2017)
      .then(() => {}, reason => done())
    })

    it('should overwrite an existing boolean property', function(done) {
      updater(destSettingsPath).set('public', false).then(() => {
        var pkg = JSON.parse(fs.readFileSync(destSettingsPath))
        assert.equal(false, pkg.public)
        done()
      })
    })

    it('should overwrite an existing string property', function(done) {
      updater(destSettingsPath).set('license', 'FREE').then(() => {
        var pkg = JSON.parse(fs.readFileSync(destSettingsPath))
        assert.equal('FREE', pkg.license)
        done()
      })
    })

    it('should overwrite an existing array property', function(done) {
      updater(destSettingsPath).set('tags', [1, 2, 4]).then(() => {
        var pkg = JSON.parse(fs.readFileSync(destSettingsPath))
        assert.equal(3, pkg.tags.length)
        assert.equal(4, pkg.tags[2])
        done()
      })
    })

    it('should overwrite an existing object property', function(done) {
      updater(destSettingsPath).set('scripts', { x: 100 }).then(() => {
        var pkg = JSON.parse(fs.readFileSync(destSettingsPath))
        assert(!('test' in pkg.scripts))
        assert.equal(100, pkg.scripts.x)
        done()
      })
    })

    describe('dot selector', function() {

      it('should throw if a property is not defined', function(done) {
        updater(destSettingsPath).set('author.skillz', 'Nunchuks')
        .then(() => {}, reason => done())
      })

      it('should throw on data type mismatch', function(done) {
        updater(destSettingsPath).set('author.hobbies', 'running')
        .then(() => {}, reason => done())
      })

      it('should overwrite an existing boolean property', function(done) {
        updater(destSettingsPath).set('author.friendly', false).then(() => {
          var pkg = JSON.parse(fs.readFileSync(destSettingsPath))
          assert.equal(false, pkg.author.friendly) // this fact is false
          done()
        })
      })

      it('should overwrite an existing string property', function(done) {
        updater(destSettingsPath).set('author.hobbies.others', 'looking').then(() => {
          var pkg = JSON.parse(fs.readFileSync(destSettingsPath))
          assert.equal('looking', pkg.author.hobbies.others)
          done()
        })
      })

      it('should overwrite an existing array property', function(done) {
        updater(destSettingsPath).set('author.hobbies.primary', [2, 9, 1]).then(() => {
          var pkg = JSON.parse(fs.readFileSync(destSettingsPath))
          assert.equal(3, pkg.author.hobbies.primary.length)
          assert.equal(1, pkg.author.hobbies.primary[2])
          done()
        })
      })

      it('should overwrite an existing object property', function(done) {
        updater(destSettingsPath).set('author.hobbies', { x: 100 }).then(() => {
          var pkg = JSON.parse(fs.readFileSync(destSettingsPath))
          assert(!('primary' in pkg.author.hobbies))
          assert.equal(100, pkg.author.hobbies.x)
          done()
        })
      })

    })

  })

  describe('.append()', function() {

    it('should throw if a property is not defined', function(done) {
      updater(destSettingsPath).append('random', '')
      .then(() => {}, reason => done())
    })

    it('should not append a boolean to a boolean property', function(done) {
      updater(destSettingsPath).append('public', true)
      .then(() => {}, reason => done())
    })

    it('should not append a boolean to a string property', function(done) {
      updater(destSettingsPath).append('license', true)
      .then(() => {}, reason => done())
    })

    it('should not append a boolean to a number property', function(done) {
      updater(destSettingsPath).append('year', true)
      .then(() => {}, reason => done())
    })

    it('should not append a boolean to an array property', function(done) {
      updater(destSettingsPath).append('tags', true)
      .then(() => {}, reason => done())
    })

    it('should not append a boolean to a object property', function(done) {
      updater(destSettingsPath).append('author', true)
      .then(() => {}, reason => done())
    })

    it('should not append a string to a boolean property', function(done) {
      updater(destSettingsPath).append('public', 'x')
      .then(() => {}, reason => done())
    })

    it('should not append a string to a number property', function(done) {
      updater(destSettingsPath).append('year', 'x')
      .then(() => {}, reason => done())
    })

    it('should not append a string to an object property', function(done) {
      updater(destSettingsPath).append('repository', 'x')
      .then(() => {}, reason => done())
    })

    it('should not append a number to a boolean property', function(done) {
      updater(destSettingsPath).append('public', 2017)
      .then(() => {}, reason => done())
    })

    it('should not append a number to a string property', function(done) {
      updater(destSettingsPath).append('license', 2017)
      .then(() => {}, reason => done())
    })

    it('should not append a number to a number property', function(done) {
      updater(destSettingsPath).append('year', 100)
      .then(() => {}, reason => done())
    })

    it('should not append a number to an object property', function(done) {
      updater(destSettingsPath).append('repository', 9)
      .then(() => {}, reason => done())
    })

    it('should not append an array to a boolean property', function(done) {
      updater(destSettingsPath).append('public', [])
      .then(() => {}, reason => done())
    })

    it('should not append an array to an string property', function(done) {
      updater(destSettingsPath).append('license', [])
      .then(() => {}, reason => done())
    })

    it('should not append an array to an number property', function(done) {
      updater(destSettingsPath).append('year', [])
      .then(() => {}, reason => done())
    })

    it('should not append an array to an object property', function(done) {
      updater(destSettingsPath).append('author', [])
      .then(() => {}, reason => done())
    })

    it('should not append an object to a boolean property', function(done) {
      updater(destSettingsPath).append('public', {})
      .then(() => {}, reason => done())
    })

    it('should not append an object to an string property', function(done) {
      updater(destSettingsPath).append('license', {})
      .then(() => {}, reason => done())
    })

    it('should not append an object to an number property', function(done) {
      updater(destSettingsPath).append('year', {})
      .then(() => {}, reason => done())
    })

    it('should append a string to a string property', function(done) {
      updater(destSettingsPath).append('license', 'COOL').then(() => {
        var pkg = JSON.parse(fs.readFileSync(destSettingsPath))
        assert.equal('MITCOOL', pkg.license)
        done()
      })
    })

    it('should push a string into an array property', function(done) {
      updater(destSettingsPath).append('tags', 'cool').then(() => {
        var pkg = JSON.parse(fs.readFileSync(destSettingsPath))
        assert(pkg.tags.includes('node'))
        assert(pkg.tags.includes('cool'))
        done()
      })
    })

    it('should push a number into an array property', function(done) {
      updater(destSettingsPath).append('tags', 100).then(() => {
        var pkg = JSON.parse(fs.readFileSync(destSettingsPath))
        assert(pkg.tags.includes('node'))
        assert(pkg.tags.includes(100))
        done()
      })
    })

    it('should push an array to an array property', function(done) {
      updater(destSettingsPath).append('tags', [500], true).then(() => {
        var pkg = JSON.parse(fs.readFileSync(destSettingsPath))
        assert(pkg.tags.includes('node'))
        assert.equal(500, pkg.tags[2][0])
        done()
      })
    })

    it('should push an object to an array property', function(done) {
      updater(destSettingsPath).append('tags', {x:900}, true).then(() => {
        var pkg = JSON.parse(fs.readFileSync(destSettingsPath))
        assert(pkg.tags.includes('node'))
        assert.equal(900, pkg.tags[2].x)
        done()
      })
    })

    it('should concat an array with an array property', function(done) {
      updater(destSettingsPath).append('tags', [100]).then(() => {
        var pkg = JSON.parse(fs.readFileSync(destSettingsPath))
        assert(pkg.tags.includes('node'))
        assert(pkg.tags.includes(100))
        done()
      })
    })

    it('should append an object to an object property', function(done) {
      updater(destSettingsPath).append('author', {
        'username': 'hacksparrow'
      }).then(() => {
        var pkg = JSON.parse(fs.readFileSync(destSettingsPath))
        assert.equal('Hage Yaapa', pkg.author.name)
        assert.equal('hacksparrow', pkg.author.username)
        done()
      })
    })

    describe('dot selector', function() {

      it('should throw if a property is not defined', function(done) {
        updater(destSettingsPath).append('author.skillz', 'Nunchuks')
        .then(() => {}, reason => done())
      })

      it('should throw on data type mismatch', function(done) {
        updater(destSettingsPath).append('author.hobbies', 'running')
        .then(() => {}, reason => done())
      })

      it('should append to an existing string property', function(done) {
        updater(destSettingsPath).append('author.hobbies.others', 's').then(() => {
          var pkg = JSON.parse(fs.readFileSync(destSettingsPath))
          assert.equal('sittings', pkg.author.hobbies.others)
          done()
        })
      })

      it('should append to an existing array property', function(done) {
        updater(destSettingsPath).append('author.hobbies.primary', 'ping pong').then(() => {
          var pkg = JSON.parse(fs.readFileSync(destSettingsPath))
          assert(pkg.author.hobbies.primary.includes('ping pong'))
          assert(pkg.author.hobbies.primary.includes('disco dance'))
          done()
        })
      })

      it('should append to an existing object property', function(done) {
        updater(destSettingsPath).append('author.hobbies', {
          'secret': 'computer hacking'
        }).then(() => {
          var pkg = JSON.parse(fs.readFileSync(destSettingsPath))
          assert.equal('computer hacking', pkg.author.hobbies.secret)
          assert.equal('Hage Yaapa', pkg.author.name)
          done()
        })
      })

    })

  })

  describe('.delete()', function() {

    it('should throw if a property is not defined', function(done) {
      updater(destSettingsPath).delete(['name', 'random'])
      .then(() => {}, reason => done())
    })

    it('should delete a single property', function(done) {
      updater(destSettingsPath).delete('name').then(() => {
        var pkg = JSON.parse(fs.readFileSync(destSettingsPath))
        assert.equal(undefined, pkg.name)
        done()
      })
    })

    it('should delete multiple properties', function(done) {
      updater(destSettingsPath).delete(['name', 'version']).then(() => {
        var pkg = JSON.parse(fs.readFileSync(destSettingsPath))
        assert(!('name' in pkg))
        assert(!('version' in pkg))
        done()
      })
    })

    describe('dot selector', function() {

      it('should throw if a property is not defined', function(done) {
        updater(destSettingsPath).delete('author.skillz')
        .then(() => {}, reason => done())
      })

      it('should delete a single property', function(done) {
        updater(destSettingsPath).delete('author.hobbies.others').then(() => {
          var pkg = JSON.parse(fs.readFileSync(destSettingsPath))
          assert.equal(undefined, pkg.author.hobbies.others)
          done()
        })
      })

      it('should delete multiple properties', function(done) {
        updater(destSettingsPath).delete(['author.hobbies.secondary', 'author.email']).then(() => {
          var pkg = JSON.parse(fs.readFileSync(destSettingsPath))
          assert(!('secondary' in pkg.author.hobbies))
          assert(!('email' in pkg.author))
          assert.equal('Hage Yaapa', pkg.author.name)
          assert(pkg.author.hobbies.primary.includes('disco dance'))
          done()
        })
      })

    })

  })

})
